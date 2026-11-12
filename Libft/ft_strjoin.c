/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:41:03 by ysalama           #+#    #+#             */
/*   Updated: 2026/11/12 22:01:07 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	s1_len;
	size_t	s2_len;
	size_t		i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined = malloc((s1_len + s2_len) * sizeof(char) + 1);
	if (!joined)
		return (NULL);
	i = -1;
	while (s1[++i])
		joined[i] = s1[i];
	i = -1;
	while (s2[++i])
	{
		joined[s1_len] = s2[i];
		s1_len++;
	}
	joined[s1_len] = '\0';
	return (joined);
}
