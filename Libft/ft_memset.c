/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:35:45 by ysalama           #+#    #+#             */
/*   Updated: 2026/10/21 19:46:39 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Issues:
//
// 1. Use raw pointers instead.
//

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int		i;
	char	*str;

	i = 0;
	str = s;
	while (n-- > 0)
		str[i++] = c;
	return (s);
}
