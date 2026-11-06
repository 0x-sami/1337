/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:01:30 by ysalama           #+#    #+#             */
/*   Updated: 2026/11/02 13:49:56 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		str_len;
	int		str_len_init;
	int		i;

	str = (char *)s;
	str_len = ft_strlen(str);
	str_len_init = str_len;
	i = 0;
	while (i <= str_len_init)
	{
		if (str[str_len] == (unsigned char)c)
			return (&str[str_len]);
		i++;
		str_len--;
	}
	return (NULL);
}
