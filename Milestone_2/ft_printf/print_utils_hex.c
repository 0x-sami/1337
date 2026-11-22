/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 10:00:28 by ysalama           #+#    #+#             */
/*   Updated: 2026/11/22 11:04:28 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_rec(uintptr_t address);
static int	add_count(int *count, int result);

int	ft_puthex(unsigned long n, char flag)
{
	int		count;

	count = 0;
	if (flag == 'x')
	{
		if (n / 16)
		{
			if (add_count(&count, ft_puthex(n / 16, flag)) == -1)
				return (-1);
		}
		if (add_count(&count, ft_putchar("0123456789abcdef"[n % 16])) == -1)
			return (-1);
	}
	else if (flag == 'X')
	{
		if (n / 16)
		{
			if (add_count(&count, ft_puthex(n / 16, flag)) == -1)
				return (-1);
		}
		if (add_count(&count, ft_putchar("0123456789ABCDEF"[n % 16])) == -1)
			return (-1);
	}
	return (count);
}

int	ft_putptr(void *ptr)
{
	uintptr_t	address;
	int			count;

	count = 0;
	if (!ptr)
	{
		if (add_count(&count, ft_putstr("(nil)")) == -1)
			return (-1);
		return (count);
	}
	address = (uintptr_t)ptr;
	if (add_count(&count, ft_putstr("0x")) == -1)
		return (-1);
	if (add_count(&count, ft_putptr_rec(address)) == -1)
		return (-1);
	return (count);
}

static int	ft_putptr_rec(uintptr_t address)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (address >= 16)
	{
		if (add_count(&count, ft_putptr_rec(address / 16)) == -1)
			return (-1);
	}
	if (add_count(&count, ft_putchar(hex[address % 16])) == -1)
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
