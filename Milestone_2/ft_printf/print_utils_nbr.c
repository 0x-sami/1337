/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 09:58:15 by ysalama           #+#    #+#             */
/*   Updated: 2026/11/22 11:09:47 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_signed(long n);
static int	ft_putnbr_unsigned(unsigned int n);
static int	add_count(int *count, int result);

int	ft_putnbr(long n, char flag)
{
	int	count;
	int	err_check;

	count = 0;
	if (flag == 'd' || flag == 'i')
	{
		err_check = ft_putnbr_signed(n);
		if (err_check == -1)
			return (-1);
		count += err_check;
	}
	else if (flag == 'u')
	{
		err_check = ft_putnbr_unsigned(n);
		if (err_check == -1)
			return (-1);
		count += err_check;
	}
	return (count);
}

static int	ft_putnbr_signed(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		if (add_count(&count, ft_putchar('-')) == -1)
			return (-1);
		n = -n;
	}
	if (n / 10)
	{
		if (add_count(&count, ft_putnbr_signed(n / 10)) == -1)
			return (-1);
	}
	if (add_count(&count, ft_putchar(n % 10 + '0')) == -1)
		return (-1);
	return (count);
}

static int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n / 10)
	{
		if (add_count(&count, ft_putnbr_unsigned(n / 10)) == -1)
			return (-1);
	}
	if (add_count(&count, ft_putchar(n % 10 + '0')) == -1)
		return (-1);
	return (count);
}

static int	add_count(int *count, int result)
{
	if (result == -1)
		return (-1);
	*count += result;
	return (0);
}
