/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:49:52 by kyoulee           #+#    #+#             */
/*   Updated: 2022/03/25 20:10:29 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, long unsigned int n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n-- > 0)
	{
		*ptr = 0;
		ptr++;
	}
}
