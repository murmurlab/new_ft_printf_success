/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:29:54 by ahbasara          #+#    #+#             */
/*   Updated: 2023/01/11 20:52:52 by ahbasara         ###   ########.fr       */
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
			ctf(str);
			ft_check_format(args, &str, &len);
			//
		}
		else
			len += _(NULL, 0, *(str++));
	}
	va_end(args);
	return (len);
}