/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 12:22:55 by ysalama           #+#    #+#             */
/*   Updated: 2026/11/06 10:37:13 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int			i;
	char		*p_d;
	const char	*p_s;

	i = 0;
	p_d = dest;
	p_s = src;
	while (n-- > 0)
	{
		p_d[i] = p_s[i];
		i++;
	}
	return (dest);
}
