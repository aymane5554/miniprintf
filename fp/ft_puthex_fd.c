/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-arr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:36:27 by ayel-arr          #+#    #+#             */
/*   Updated: 2024/11/08 10:36:29 by ayel-arr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numlen(unsigned int n)
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

static unsigned int	power16(int n)
{
	unsigned int	num;

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

static int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

static char	case_handling(char c, char casee)
{
	if (casee == 'u')
		return (ft_toupper(c));
	return (c);
}

int	ft_puthex_fd(unsigned int n, int fd, char casee)
{
	unsigned int	nl;
	char			c;
	char			*hex;

	if (fd < 0)
		return (0);
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	hex = "0123456789abcdef";
	nl = numlen(n);
	while (nl > 0)
	{
		c = ft_abs((n / power16(nl - 1)) % 16);
		c = case_handling(hex[(int)c], casee);
		write(fd, &c, 1);
		nl--;
	}
	return (numlen(n));
}
