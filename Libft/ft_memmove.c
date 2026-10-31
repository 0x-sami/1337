/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 13:13:30 by ysalama           #+#    #+#             */
/*   Updated: 2026/10/31 17:55:41 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*p_d;
	const char	*p_s;

	p_d = (char *)dest;
	p_s = (const char *)src;
	if (p_d < p_s)
	{
		while (n--)
			*p_d++ = *p_s++;
	}
	else if (p_d > p_s)
	{
		p_d += n;
		p_s += n;
		while (n--)
			*(--p_d) = *(--p_s);
	}
	return (dest);
}
