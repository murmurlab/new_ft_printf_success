/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:29:50 by hece              #+#    #+#             */
/*   Updated: 2023/01/10 13:30:17 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			//ctf();
			ft_check_format(args, &str, &len);
		}
		else
			len += _(NULL, 0, *(str++));
	}
	va_end(args);
	return (len);
}

/* (
	((*s != '%') && ((lne += mr_putstr(NULL, 0, *s++)) || 1))
	|| (((*(++s)) == 'c' && s++) && ((lne += mr_putstr(NULL, 0, va_arg(argl, int))) || 1))
	|| ((*s == 's' && s++) && ((lne += mr_putstr(va_arg(argl, char*), 1, 0)) || 1))
	|| ((*s == 'u' && s++) && ((lne += itoa_base_v2(va_arg(argl, unsigned int), "0123456789", 0)) || 1))
	|| (((*s == 'd' || *s == 'i' || *s == 'u') && s++) && ((lne += itoa_base_v2(va_arg(argl, int), "0123456789", 1)) || 1))
	|| ((*s == 'p' && s++) && ((lne += (mr_putstr("0x", 1, 0) + itoa_base_v2(va_arg(argl, unsigned long), "0123456789abcdef", 0))) || 1))
	|| ((*s == 'x' && s++) && ((lne += itoa_base_v2(va_arg(argl, unsigned int), "0123456789abcdef", 0)) || 1))
	|| ((*s == 'X' && s++) && ((lne += itoa_base_v2(va_arg(argl, unsigned int), "0123456789ABCDEF", 0)) || 1))
	|| ((*s == '%' && s++) && ((lne += mr_putstr(NULL, 0, '%')) || 1))
); */

/* 
	while (*s)
	{
		tmp = (-1 *~(0 + !(((*s != '%') && (write(1, s, 1) || 1)) || !(((* (s + 1\
		) == 'c') && (lne += mr_putstr(NULL, 1, va_arg(argl, int)) || 1)) || ((*(s + 1 \
		) == 's') && (lne += mr_putstr(va_arg(argl, char*), 1, 0) || 1)) || ((*(s + 1) \
		== 'p') && (lne += 2 + itoa_base_v2(va_arg(argl, unsigned long), "0123456789abcdef"\
		, (mr_putstr("0x", 2, 0) && 0)) || 1)) || ((*(s + 1) == 'd') && (\
		(lne += itoa_base_v2(va_arg(argl, int), "0123456789", 1)) || 1)) || ((*(s + 1) ==\
		'x') && (lne += itoa_base_v2(va_arg(argl, unsigned int), "0123456789abcdef", 0 \
		) || 1)) || ((*(s + 1) == 'X') && (lne += itoa_base_v2(va_arg(argl, unsigned \
		int), "0123456789ABCDEF", 0) || 1)) || ((*(s + 1) == 'u') && (\
		lne += itoa_base_v2(va_arg(argl, unsigned int), "0123456789", 1) || 1)) || 1)))\
		);
		s += tmp;
		lne += tmp;
	}
	return ((int)lne); */