/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:02:17 by kyoulee           #+#    #+#             */
/*   Updated: 2022/03/25 20:26:37 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, long unsigned int len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len-- > 0)
		*ptr++ = c;
	return (b);
}
