/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 18:11:42 by ysalama           #+#    #+#             */
/*   Updated: 2026/10/24 11:53:31 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	i = 0;
	while (s[i])
	{
		res = malloc(ft_strlen(s) * sizeof(char) + 1);
		if (!res)
			return (NULL);
		res[i] = f(i, s[i]);
	}
	return (res);
}
