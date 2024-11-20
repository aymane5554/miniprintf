/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-arr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:24:13 by ayel-arr          #+#    #+#             */
/*   Updated: 2024/11/05 20:24:16 by ayel-arr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static void	fnorm2(const char *s, int *count)
{
	write(1, s + 1, 1);
	*(count) += 1;
}

static void	fnorm(const char *s, va_list ptr, int *count)
{
	if (*s == '%' && *(s + 1) == '%')
	{
		write(1, "%", 1);
		*(count) += 1;
	}
	else if (*s == '%' && *(s + 1) == 'i')
		*(count) += ft_putnbr_fd(va_arg(ptr, int), 1);
	else if (*s == '%' && *(s + 1) == 'd')
		*(count) += ft_putnbr_fd(va_arg(ptr, int), 1);
	else if (*s == '%' && *(s + 1) == 's')
		*(count) += ft_putstr_fd(va_arg(ptr, char *), 1);
	else if (*s == '%' && *(s + 1) == 'c')
		*(count) += ft_putchar_fd(va_arg(ptr, int), 1);
	else if (*s == '%' && *(s + 1) == 'x')
		*(count) += ft_puthex_fd(va_arg(ptr, unsigned long), 1, 'l');
	else if (*s == '%' && *(s + 1) == 'X')
		*(count) += ft_puthex_fd(va_arg(ptr, unsigned long), 1, 'u');
	else if (*s == '%' && *(s + 1) == 'u')
		*(count) += ft_putu_fd(va_arg(ptr, unsigned int), 1);
	else if (*s == '%' && *(s + 1) == 'p')
		*(count) += ft_putptr_fd((unsigned long)va_arg(ptr, void *),
				1, 'l');
	else
		fnorm2(s, count);
}

int	ft_printf(const char *s, ...)
{
	va_list		ptr;
	int			count;

	if (write(1, "", 0) == -1)
		return (-1);
	count = 0;
	va_start(ptr, s);
	while (*s)
	{
		if (*s != '%')
		{
			write(1, s, 1);
			count++;
			s++;
			continue ;
		}
		else if (*s == '%' && *(s + 1) == '\0')
			return (count);
		fnorm(s, ptr, &count);
		s = s + 2;
	}
	va_end(ptr);
	return (count);
}
