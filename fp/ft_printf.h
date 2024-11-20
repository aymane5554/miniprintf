/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-arr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:51:57 by ayel-arr          #+#    #+#             */
/*   Updated: 2024/11/08 10:52:00 by ayel-arr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>

int	ft_puthex_fd(unsigned int n, int fd, char casee);
int	ft_putu_fd(unsigned int n, int fd);
int	ft_putptr_fd(unsigned long n, int fd, char casee);
int	ft_printf(const char *s, ...);
int	ft_putchar_fd(char c, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_toupper(int c);
#endif
