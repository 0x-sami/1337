/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 10:50:54 by ysalama           #+#    #+#             */
/*   Updated: 2026/11/09 19:24:13 by ysalama          ###   ########.fr       */
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

int ft_putnbr(long n, char flag)
{
	int count;

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

int ft_puthex(long n, char flag)
{
	char *lower;
	char *upper;
	int count;

	lower = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	count = 0;
	if (flag == 'x')
	{
		if (n / 10)
			count += ft_puthex(n / 10, flag);
		count += ft_putchar(lower[n % 16]);
	}
	else if (flag == 'X')
	{
		if (n / 10)
			count += ft_puthex(n / 10, flag);
		count += ft_putchar(upper[n % 16]);
	}
	else if (flag == 'p')
	{
		count += ft_putstr("0x");
	}
	return (count);
}

int	ft_putptr(void *ptr)
{
	
}
