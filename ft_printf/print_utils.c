/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 10:50:54 by ysalama           #+#    #+#             */
/*   Updated: 2026/11/11 20:19:23 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	s_len;

	s_len = ft_strlen(s);
	write(1, s, s_len);
	return (s_len);
}

int	ft_putnbr(long n, char flag)
{
	int	count;

	count = 0;
	if (flag == 'd' || flag == 'i')
	{
		if (n < 0)
		{
			count += ft_putchar('-');
			n = -n;
		}
		if (n / 10)
			count += ft_putnbr(n / 10, flag);
		count += ft_putchar(n % 10 + '0');
	}
	else if (flag == 'u')
	{
		if (n / 10)
			count += ft_putnbr(n / 10, flag);
		count += ft_putchar(n % 10 + '0');
	}
	return (count);
}

// TODO: remove the hex variables

int	ft_puthex(unsigned long long n, char flag)
{
	char	*lower_hex;
	char	*upper_hex;
	int		count;

	lower_hex = "0123456789abcdef";
	upper_hex = "0123456789ABCDEF";
	count = 0;
	if (flag == 'x')
	{
		if (n / 10)
			count += ft_puthex(n / 10, flag);
		count += ft_putchar(lower_hex[n % 16]);
	}
	else if (flag == 'X')
	{
		if (n / 10)
			count += ft_puthex(n / 10, flag); // TODO: check whether lines like this change `count`
		count += ft_putchar(upper_hex[n % 16]);
	}
	return (count);
}

int	ft_putptr(void *ptr)
{
	char		*hex;
	uintptr_t	address;
	int			count;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	hex = "0123456789abcdef";
	address = (uintptr_t)ptr;
	count += write(1, "0x", 2);
	if (address >= 16)
		count += ft_puthex(address / 16, 'x');
	count += write(1, &hex[address % 16], 1);
	return (count);
}
#include <stdio.h>
int main()
{
	int n = 1;
	ft_putptr((void *)&n);
	//ft_putptr(NULL);
	printf("\n%p\n", (void *)&n);
	//printf("\n%p\n", NULL);
}
