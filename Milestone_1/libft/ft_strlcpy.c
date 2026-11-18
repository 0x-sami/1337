/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:35:16 by ysalama           #+#    #+#             */
/*   Updated: 2026/10/26 23:43:18 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (src_len == 0)
	{
		dst[0] = '\0';
		return (0);
	}
	if (src_len < size)
	{
		dst[src_len] = '\0';
		ft_memcpy(dst, src, src_len);
		return (src_len);
	}
	ft_memcpy(dst, src, size);
	dst[size - 1] = '\0';
	return (src_len);
}
