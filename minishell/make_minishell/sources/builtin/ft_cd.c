/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:59:28 by sanghan           #+#    #+#             */
/*   Updated: 2023/01/04 15:27:24 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_cd(t_parser_token *parser_token)
{
	char		*path;
	int			res;
	static char	*cwd;
	char		*temp;

	res = 0;
	temp = NULL;
	cwd = getcwd(NULL, 0);
	if (parser_token->cmd->next == NULL)
	{
	}

}
