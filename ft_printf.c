/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:29:50 by hece              #+#    #+#             */
/*   Updated: 2023/01/09 13:47:12 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long int	_(char *s, char p, char kar)
{
	unsigned long long int	i;

	i = 0;
	if (p && !s)
		return (write(1, "(null)", 6));
	while (s && s[i])
		write(1, &s[i++], p);
	return ((!s && write(1, &kar, (!s || 0))) + i);
}

unsigned long long int	x(unsigned long long int i, char *s, char m)
{
	unsigned long long int	digit;
	unsigned long long int	lne;
	char					base;

	base = _(s, 0, 0);
	lne = 1;
	digit = 1;
	if (m && (long long int)i < 0)
	{
		write(1, "-", (lne++ || 1));
		i *= -1;
	}
	while ((digit * base) && i / (digit * base))
		digit *= (base * (lne++ || 1));
	while (digit && (i / digit || !i))
	{
		_(NULL, 0, s[(i / digit) % base]);
		digit /= base;
	}
	return (lne);
}

int	ft_check_format(va_list argl, const char **str, int len)
{
	if (**str != '%')
		len += ft_putchar(*(*str)++);
	else if ((*++(*str)) == 'c' && (*str)++)
		len += _(NULL, 0, va_arg(argl, int));
	else if ((**str) == 's' && (*str)++)
		len += _(va_arg(argl, char*), 1, 0);
	else if ((**str) == 'u' && (*str)++)
		len += x(va_arg(argl, unsigned int), "0123456789", 0);
	else if (((**str) == 'd' || (**str) == 'i' || (**str) == 'u') && (*str)++)
		len += x(va_arg(argl, int), "0123456789", 1);
	else if ((**str) == 'p' && (*str)++)
		len += (_("0x", 1, 0) + x(va_arg(argl, unsigned long), \
		"0123456789abcdef", 0));
	else if ((**str) == 'x' && (*str)++)
		len += x(va_arg(argl, unsigned int), "0123456789abcdef", 0);
	else if ((**str) == 'X' && (*str)++)
		len += x(va_arg(argl, unsigned int), "0123456789ABCDEF", 0);
	else if ((**str) == '%' && (*str)++)
		len += _(NULL, 0, '%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, str);
	while (*str != '\0')
		len += ft_check_format(args, &str, 0);
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