/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:47:46 by sanghan           #+#    #+#             */
/*   Updated: 2022/09/01 20:21:41 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int			ft_printf(const char *str, ...);
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_puthex(int i, char x);
int			ft_itoa(int n);
int			ft_uitoa(int n);
int			ft_putpointer(unsigned long long l);
int			charcount(unsigned long long nb);
void		putnbr_base(unsigned long long nb, char *base);

#endif
