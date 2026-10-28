/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:26:48 by ysalama           #+#    #+#             */
/*   Updated: 2026/10/28 15:57:03 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	sub = malloc(len * sizeof(char) + 1);
	if (!sub)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	ft_strlcpy(sub, s + start, len + 1);
	sub[ft_strlen(sub)] = '\0';
	return (sub);
}
/*
#include <stdio.h>
int main()
{
	printf("%s$\n", ft_substr("tripouille", 0, 42000));
	printf("%zu$\n", ft_strlen(ft_substr("tripouille", 0, 42000)));
}
*/
