/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:53:20 by sanghan           #+#    #+#             */
/*   Updated: 2023/01/09 16:27:23 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin(t_exec_token *token)
{
	char	*cmd;

	cmd = token->parser_token->cmd->content;
	if (ft_strncmp(cmd, "env", 4) == 0 || \
		ft_strncmp(cmd, "export", 7) == 0 || \
		ft_strncmp(cmd, "unset", 6) == 0 || \
		ft_strncmp(cmd, "cd", 3) == 0 || \
		ft_strncmp(cmd, "echo", 5) == 0 || \
		ft_strncmp(cmd, "exit", 5) == 0 || \
		ft_strncmp(cmd, "pwd", 4) == 0)
		return (1);
	else
		return (0);
}

void	exec_builtin(t_exec_token *token, t_env *env_list)
{
	char	*cmd;

	cmd = token->cmd[0];
	if (ft_strncmp(cmd, "env", 4) == 0)
		ft_env(token->cmd, env_list);

	else if (ft_strncmp(cmd, "export", 7) == 0)
		ft_export(token->cmd, env_list);

	else if (ft_strncmp(cmd, "unset", 6) == 0)
		ft_unset(token->cmd, env_list);

	else if (ft_strncmp(cmd, "cd", 3) == 0)
		ft_cd(token->parser_token);

	else if (ft_strncmp(cmd, "echo", 5) == 0)
		ft_echo(token);

	else if (ft_strncmp(cmd, "exit", 5) == 0)
		ft_exit(token->parser_token);

	else if (ft_strncmp(cmd, "pwd", 4) == 0)
		ft_pwd(token->cmd);
}
