/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:29:50 by hece              #+#    #+#             */
/*   Updated: 2022/12/27 01:43:57 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	len;
	int	index;

	index = 0;
	len = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[index] != '\0')
		len += ft_putchar(str[index++]);
	return (len);
}

int	ft_itoa_base(unsigned long long nbr, int base, char *str, int mod)
{
	int	nbr_list[100];
	int	index;
	int	len;

	index = 0;
	len = 0;
	if (mod == 1 && (int)nbr < 0)
	{
		nbr *= -1;
		len += ft_putchar('-');
	}
	if (mod == 2)
		len += ft_putstr("0x");
	if (nbr == 0)
		len += ft_putchar('0');
	while (nbr)
	{
		nbr_list[index++] = nbr % base;
		nbr = nbr / base;
	}
	while (index--)
		len += ft_putchar(str[nbr_list[index]]);
	return (len);
}

int	ft_check_format(va_list args, const char **str, int len)
{
	if (**str != '%')
		len += ft_putchar(*(*str)++);
	else if ((*++(*str)) == 'c' && (*str)++)
		len += ft_putchar(va_arg(args, int));
	else if ((**str) == 's' && (*str)++)
		len += ft_putstr(va_arg(args, char *));
	else if ((**str) == 'u' && (*str)++)
		len += ft_itoa_base(va_arg(args, unsigned int), 10, "0123456789", 0);
	else if (((**str) == 'd' || (**str) == 'i' || (**str) == 'u') && (*str)++)
		len += ft_itoa_base(va_arg(args, int), 10, "0123456789", 1);
	else if ((**str) == 'p' && (*str)++)
		len += ft_itoa_base(va_arg(args, unsigned long long), 16,
				"0123456789abcdef", 2);
	else if ((**str) == 'x' && (*str)++)
		len += ft_itoa_base(va_arg(args, unsigned int), 16,
				"0123456789abcdef", 0);
	else if ((**str) == 'X' && (*str)++)
		len += ft_itoa_base(va_arg(args, unsigned int), 16,
				"0123456789ABCDEF", 0);
	else if ((**str) == '%' && (*str)++)
		len += ft_putchar('%');
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
/* #include <stdio.h>
int	main(void)
{
	//int a;
	//void	*p = &a;
	char b;

	b = 'w';
	printf("%d\n", ft_printf("|my,   |%d| asdds|", 12333));
	printf("%d", printf("|or,   |%d| asdds|", 12333));
} */