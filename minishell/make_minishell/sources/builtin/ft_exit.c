/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:05:31 by sanghan           #+#    #+#             */
/*   Updated: 2023/01/05 20:27:04 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_exit(t_parser_token *parser_token)
{
	int	code;

	if (parser_token->cmd == NULL)
		return (0);
	if (parser_token->cmd->next == NULL)
		exit(0);
	code = ft_atoi(parser_token->cmd->next->content);
	exit(code);
}
