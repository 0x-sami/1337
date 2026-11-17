/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:46:02 by ysalama           #+#    #+#             */
/*   Updated: 2026/11/17 11:55:38 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_handler(char c, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		err_check;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if ((err_check = ft_print_handler(format[i], args)) == -1)
			{
				count = -1;
				break ;
			}
			else
				count += err_check;
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
		count = write(1, "%", 1);
	return (count);
}

/*
#include <stdio.h>
#include <sys/syscall.h>
static int i = 0;
ssize_t write(int v, const void  *buf, size_t o)
{
	if (i < 4)
	{
		i++;
		return syscall(SYS_write,v,buf,o);
	}
	else
		return -1;
}
int main()
{
	dprintf(2,"%d",ft_printf("%d",12345));
}
*/
/*
#include <stdio.h>
int main()
{
	int i = 0;
	ft_printf("ft_printf: ");
	i = ft_printf("%d, %c, %s, %p", 17, 'a', "Hello", &i);
	ft_printf("\nNumber of chars printed: %d\n", i);
	printf("\n");
	int j = 0;
	printf("---printf: ");
	j = printf("%d, %c, %s, %p", 17, 'a', "Hello", &i);
	printf("\nNumber of chars printed: %d\n", j);
}
*/
