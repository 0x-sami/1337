/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 15:14:43 by ysalama           #+#    #+#             */
/*   Updated: 2026/10/31 17:55:56 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	int		j;
	char	*empty;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (ft_strchr(set, s1[i]))
		i++;
	if (i == ft_strlen(s1) + 1 || ft_strlen(s1) == 0)
	{
		empty = malloc(1);
		*empty = '\0';
		return (empty);
	}
	while (ft_strchr(set, s1[j - 1]))
		j--;
	return (ft_substr(s1, i, j - i));
}
