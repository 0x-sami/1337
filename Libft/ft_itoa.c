/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:15:56 by ysalama           #+#    #+#             */
/*   Updated: 2026/10/29 12:21:55 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	n_len(int n);
void	strrev(char *res);

char	*ft_itoa(int n)
{
	char	*res;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	res = malloc(n_len(n) + 1);
	if (!res)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		res[0] = '-';
		i++;
		n = -n;
	}
	while (n)
	{
		res[i++] = (n % 10) + '0';
		n = n / 10;
	}
	res[i] = '\0';
	strrev(res);
	return (res);
}

void	strrev(char *res)
{
	char	tmp;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(res) - 1;
	if (res[start] == '-')
		start++;
	while(res[start] && start < end)
	{
		tmp = res[start];
		res[start] = res[end];
		res[end] = tmp;
		start++;
		end--;
	}
}

int	n_len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
