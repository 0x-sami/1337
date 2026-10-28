/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:59:04 by ysalama           #+#    #+#             */
/*   Updated: 2026/10/28 20:44:18 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_all(char **result, int count);
static char	**fill(char **result, char const *s, char c, int segments);
static int	nsegments(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		segments;

	if (!s)
		return (NULL);
	segments = nsegments(s, c);
	result = malloc((segments + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (fill(result, s, c, segments));
}

static void	*free_all(char **result, int count)
{
	while (count > 0)
		free(result[--count]);
	free(result);
	return (NULL);
}

static char	**fill(char **result, char const *s, char c, int segments)
{
	int		i;
	size_t	len;

	i = 0;
	while (i < segments)
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		result[i] = malloc(len + 1);
		if (!result[i])
			return (free_all(result, i));
		ft_memcpy(result[i], s, len);
		result[i][len] = '\0';
		s += len;
		i++;
	}
	result[i] = NULL;
	return (result);
}

static int	nsegments(char const *s, char c)
{
	int	i;
	int	segments;

	i = 0;
	segments = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] == c)
			i++;
		else if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
		{
			i++;
			segments++;
		}
		i++;
	}
	return (segments);
}
