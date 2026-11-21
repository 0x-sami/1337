/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:46:02 by ysalama           #+#    #+#             */
/*   Updated: 2026/11/21 18:10:08 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_handler(char c, va_list args);
static int	bonus_helper(char specifier, char isbonus_specifier, int flag);
static int	ft_bonusprint_handler(char specifier, char bonus, va_list args);
static int	ft_check_error(char const *f, va_list args);

int	ft_printf(const char *f, ...)
{
	va_list	args;
	int		count;

	if (!f)
		return (-1);
	va_start(args, f);
	count = ft_check_error(f, args);
	va_end(args);
	return (count);
}

static int	ft_check_error(const char *f, va_list args)
{
	int	count;
	int	err_check;
	int	i;

	count = 0;
	i = -1;
	while (f[++i])
	{
		if (f[i] == '%' && bonus_helper(f[i + 2], f[i + 1], 1))
		{
			i += 2;
			err_check = ft_bonusprint_handler(f[i], f[i - 1], args);
		}
		else if (f[i] == '%' && !bonus_helper(f[i + 2], f[i + 1], 1))
			err_check = ft_print_handler(f[++i], args);
		else
			err_check = write(1, &f[i], 1);
		if (err_check == -1)
			return (-1);
		count += err_check;
	}
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
	else
		return (-1);
	return (count);
}

static int	bonus_helper(char specifier, char isbonus_specifier, int flag)
{
	int	count;

	if (flag == 1)
	{
		if (isbonus_specifier == '+' || isbonus_specifier == ' ')
		{
			if (specifier == 'd' || specifier == 'i')
				return (1);
		}
		else if (isbonus_specifier == '#')
		{
			if (specifier == 'x' || specifier == 'X')
				return (1);
		}
	}
	count = 0;
	if (flag == 2)
	{
		count += ft_putchar('0');
		count += ft_putchar(specifier);
		if (count <= 0)
			return (-1);
	}
	return (count);
}

static int	ft_bonusprint_handler(char specifier, char bonus, va_list args)
{
	va_list	temp;
	int		count;
	int		result;

	count = 0;
	if (bonus == '+' || bonus == ' ')
	{
		va_copy(temp, args);
		if (va_arg(temp, int) >= 0)
			count = ft_putchar(bonus);
		va_end(temp);
	}
	else if (bonus == '#')
	{
		va_copy(temp, args);
		if (va_arg(temp, unsigned int) != 0)
			count = bonus_helper(specifier, 0, 2);
		va_end(temp);
	}
	if (count == -1)
		return (-1);
	result = ft_print_handler(specifier, args);
	if (result == -1)
		return (-1);
	return (count + result);
}
