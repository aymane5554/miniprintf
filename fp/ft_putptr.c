/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-arr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 09:11:55 by ayel-arr          #+#    #+#             */
/*   Updated: 2024/11/09 09:11:57 by ayel-arr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numlen(unsigned long n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static long	power16(int n)
{
	long		num;

	num = 16;
	if (n == 0)
		return (1);
	n--;
	while (n > 0)
	{
		num *= 16;
		n--;
	}
	return (num);
}

static char	case_handling(char c, char casee)
{
	if (casee == 'u')
		return (ft_toupper(c));
	return (c);
}

int	ft_putptr_fd(unsigned long n, int fd, char casee)
{
	unsigned long	nl;
	char			c;
	char			*hex;

	write(fd, "0x", 2);
	if (fd < 0)
		return (0);
	if (n == 0)
	{
		write(fd, "0", 1);
		return (3);
	}
	hex = "0123456789abcdef";
	nl = numlen(n);
	while (nl > 0)
	{
		c = (n / power16(nl - 1)) % 16;
		c = case_handling(hex[(int)c], casee);
		write(fd, &c, 1);
		nl--;
	}
	return (numlen(n) + 2);
}
