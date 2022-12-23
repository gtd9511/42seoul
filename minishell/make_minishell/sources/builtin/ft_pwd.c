/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:38:57 by sanghan           #+#    #+#             */
/*   Updated: 2023/01/04 14:48:20 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_pwd(t_parser_token *parser_token)
{
	char	*path;

	if (parser_token->cmd == NULL)
		return (0);
	path = getcwd(NULL, 0);
	if (!path)
	{
		ft_putstr_fd("Error Path\n", STDERR_FILENO);
		return (1);
	}
	ft_putstr_fd(path, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	free(path);
	return (0);
}
