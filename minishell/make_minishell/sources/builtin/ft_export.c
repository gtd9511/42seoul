/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:05:35 by sanghan           #+#    #+#             */
/*   Updated: 2023/01/04 16:42:14 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_key_in_env_list(char *key, t_env *env_list)
{
	t_env	*temp;

	if (!key)
		return (0);
	temp = env_list;
	while (temp)
	{
		
	}
}

void	execute_export(char *key, char *value, t_env *env_list)
{
	t_env	*node;

	if (is_key_)
}

int	ft_export(char **cmd, t_env *env_list)
{
	int		i;
	int		j;
	char	*key;
	char	*value;

	if (cmd[i] == NULL)
		print_env_list(env_list);
	i = 1;
	while (cmd[i] != NULL)
	{
		j = 0;
		while (cmd[i][j] && cmd[i][j] != '=')
			j++;
		key = ft_substr(cmd[i], 0, j); // 할당 실패 했을 때 처리 여부  //일단 함수 안에서 널 체크 하는 정도로만 작성
		value = ft_substr(cmd[i], j + 1, ft_strlen(cmd[i]) - j - 1);
		execute_export(key, value, env_list);
		i++;
	}
	return (1);
}
