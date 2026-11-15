/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 09:58:15 by ysalama           #+#    #+#             */
/*   Updated: 2026/11/15 11:46:13 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_signed(long n);
static int	ft_putnbr_unsigned(unsigned int n);

int	ft_putnbr(long n, char flag)
{
	int	count;

	count = 0;
	if (flag == 'd' || flag == 'i')
		count += ft_putnbr_signed(n);
	else if (flag == 'u')
		count += ft_putnbr_unsigned((unsigned int)n);
	return (count);
}

static int	ft_putnbr_signed(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n / 10)
		count += ft_putnbr_signed(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

static int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n / 10)
		count += ft_putnbr_unsigned(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}
