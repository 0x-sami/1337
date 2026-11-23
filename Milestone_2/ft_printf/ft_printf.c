/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:46:02 by ysalama           #+#    #+#             */
/*   Updated: 2026/11/23 19:23:49 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_handler(char c, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		err_check;
	int		i;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			err_check = ft_print_handler(format[++i], args);
		else
			err_check = write(1, &format[i], 1);
		if (err_check == -1)
		{
			va_end(args);
			return (-1);
		}
		else
			count += err_check;
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
		count = ft_putchar(va_arg(args, int));
	else if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count = ft_putnbr(va_arg(args, int), c);
	else if (c == 'u')
		count = ft_putnbr(va_arg(args, unsigned int), c);
	else if (c == 'x' || c == 'X')
		count = ft_puthex(va_arg(args, unsigned int), c);
	else if (c == 'p')
		count = ft_putptr(va_arg(args, void *));
	else if (c == '%')
		count = ft_putchar('%');
	else
		return (-1);
	return (count);
}
