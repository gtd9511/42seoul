/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:40:50 by kyoulee           #+#    #+#             */
/*   Updated: 2022/03/28 14:10:16 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long unsigned int	ft_strlen(const char *s)
{
	long unsigned int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}
