/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:15:56 by ysalama           #+#    #+#             */
/*   Updated: 2026/10/26 22:02:48 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*handle_negative(int n);
char	*handle_positive(int n);
int	handle_negative_indexing(int i, int n);

char	*ft_itoa(int n)
{
	if (n > 0)
		return (handle_positive(n));
	return (handle_negative(n));
}

char	*handle_negative(int n)
{
	int		i;
	char	*res;

	i = 0;
	if (n == -2147483648)
		return ("-2147483648");
	i = handle_negative_indexing(i, n);
	res = malloc((i + 1) * sizeof(char));
	ft_memset(res, '0', i);
	n *= -1;
	while (i > 0)
	{
		res[i - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	res[0] = '-';
	return (res);
}

int	handle_negative_indexing(int i, int n)
{
	i = 0;
	n *= -1;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	i++;
	return (i);
}

char	*handle_positive(int n)
{
	int		i;
	int		n_n;
	char	*res;

	i = 0;
	n_n = n;
	while (n_n > 0)
	{
		n_n /= 10;
		i++;
	}
	res = malloc(i * sizeof(char));
	if (!res)
		return (NULL);
	ft_memset(res, '0', i);
	while (i > 0)
	{
		res[i - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (res);
}
