/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:24:15 by ysalama           #+#    #+#             */
/*   Updated: 2026/11/13 11:14:59 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_putptr_rec(uintptr_t address)
{
	char *hex;
	int	count;

	hex = "0123456789abcdef";
	count = 0;
	if (address > 16)
		count += ft_putptr_rec(address / 16);
	count += write(1, &hex[address % 16], 1);
	return (count);
}
