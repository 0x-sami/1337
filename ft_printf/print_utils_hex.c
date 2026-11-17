/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 10:00:28 by ysalama           #+#    #+#             */
/*   Updated: 2026/11/17 12:03:26 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_rec(uintptr_t address);

int	ft_puthex(unsigned long n, char flag)
{
	int		count;
	int		err_check;

	count = 0;
	if (flag == 'x')
	{
		if (n / 16)
			count += ft_puthex(n / 16, flag);
		if ((err_check = ft_putchar("0123456789abcdef"[n % 16])) == -1)
			return (-1);
		else
			count += err_check;
	}
	else if (flag == 'X')
	{
		if (n / 16)
			count += ft_puthex(n / 16, flag);
		if ((err_check = ft_putchar("0123456789ABCDEF"[n % 16])) == -1)
			return (-1);
		else
			count += err_check;
	}
	return (count);
}

int	ft_putptr(void *ptr)
{
	uintptr_t	address;
	int			count;
	int			err_check;

	if (!ptr)
	{
		if ((err_check = write(1, "(nil)", 5)) == -1)
				return (-1);
		else
			return (5);
	}
	count = 0;
	address = (uintptr_t)ptr;
	if ((err_check = write(1, "0x", 2)) == -1)
		return (-1);
	else
		count += err_check;
	count += ft_putptr_rec(address);
	return (count);
}

static int	ft_putptr_rec(uintptr_t address)
{
	char	*hex;
	int		count;
	int		err_check;

	hex = "0123456789abcdef";
	count = 0;
	if (address >= 16)
		count += ft_putptr_rec(address / 16);
	if ((err_check = write(1, &hex[address % 16], 1)) == -1)
		return (-1);
	else
		count += err_check;
	return (count);
}
