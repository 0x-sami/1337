/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:46:02 by ysalama           #+#    #+#             */
/*   Updated: 2026/11/15 11:47:37 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_handler(char c, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (count == -1)
			return (-1);
		if (format[i] == '%')
		{
			i++;
			count += ft_print_handler(format[i], args);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

static int	ft_print_handler(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 0)
		return (-1);
	else if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int), c);
	else if (c == 'u')
		count += ft_putnbr(va_arg(args, unsigned int), c);
	else if (c == 'x' || c == 'X')
		count += ft_puthex(va_arg(args, unsigned int), c);
	else if (c == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (c == '%')
		count += write(1, "%", 1);
	return (count);
}

/*
#include <stdio.h>
int main()
{
	int i = 0;
	ft_printf("ft_printf: ");
	i = ft_printf("%p", NULL);
	ft_printf("\nNumber of chars printed: %d\n", i);
	printf("\n");
	int j = 0;
	printf("   printf: ");
	j = printf("%p", NULL);
	printf("\nNumber of chars printed: %d\n", i);
}
*/
