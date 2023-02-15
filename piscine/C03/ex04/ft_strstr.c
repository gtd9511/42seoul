/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:48:11 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/18 16:41:52 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char	*str, char *to_find)
{
	int		pos;

	if (to_find[0] == '\0')
		return (str);
	while (*str != '\0')
	{
		pos = 0;
		while (*(str + pos) == *(to_find + pos))
		{
			pos++;
			if (*(to_find + pos) == '\0')
				return (str);
		}
		str++;
	}
	return (0);
}
