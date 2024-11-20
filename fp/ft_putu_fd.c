/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-arr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:16:52 by ayel-arr          #+#    #+#             */
/*   Updated: 2024/11/08 11:16:53 by ayel-arr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numlen(unsigned int n)
{
	int		i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	power10(int n)
{
	int		num;

	num = 10;
	if (n == 0)
		return (1);
	n--;
	while (n > 0)
	{
		num *= 10;
		n--;
	}
	return (num);
}

int	ft_putu_fd(unsigned int n, int fd)
{
	unsigned int	nl;
	char			c;

	if (fd < 0)
		return (0);
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	nl = numlen(n);
	while (nl > 0)
	{
		c = (n / power10(nl - 1)) % 10;
		c += '0';
		write(fd, &c, 1);
		nl--;
	}
	return (numlen(n));
}
