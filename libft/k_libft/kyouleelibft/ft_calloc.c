/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:31:27 by kyoulee           #+#    #+#             */
/*   Updated: 2022/03/25 19:28:45 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(long unsigned int count, long unsigned int size)
{
	unsigned char		*ptr;
	long unsigned int	ptr_len;

	if (count == 0)
		count = 1;
	ptr_len = size * count;
	ptr = (unsigned char *)malloc(ptr_len);
	if (ptr == NULL)
		return (NULL);
	while (ptr_len-- > 0)
		ptr[ptr_len] = '\0';
	return ((void *)ptr);
}
