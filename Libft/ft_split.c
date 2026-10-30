/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 14:17:28 by ysalama           #+#    #+#             */
/*   Updated: 2026/10/30 17:37:47 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**fill(char **result, char const *s, char c, int segments);
int	nsegments(char const *s, char c);
int	handle_mem(char **result, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		segments;

	// Handling memory allocation
	// Allocating the entire split
	segments = nsegments(s, c) + 1;
	result = malloc(segments * sizeof(char *));
	if (!result)
		return (NULL);
	// Allocating individual elements in the split
	if (!handle_mem(result, s, c))
		return (NULL);
	// Fill result and return
	result = fill(result, s, c, segments);
	result[segments] = NULL;
	return (result);
}

char	**fill(char **result, char const *s, char c, int segments)
{
	int	i;
	int	j;
	int	fill_index;

	i = 0;
	j = 0;
	fill_index = 0;
	while (s[i + 1])
	{
		if (s[i] == c && s[i + 1] == c)
			i++;
		else if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			|| s[i--] != c && s[i + 1] != c)
		{
			while (s[++i] != c)
				j++;
			result[fill_index] = ft_substr(s, i - j, j);
			fill_index++;
			j = 0;
		}
	}
	return (result);
}

int	nsegments(char const *s, char c)
{
	int	i;
	int	segments;

	i = 0;
	segments = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] == c)
			i++;
		else if (s[i] == c && (s[i + 1] != c || s[i + 1] != '\0'))
		{
			i++;
			segments++;
		}
		i++;
	}
	return (segments + 1);
}

int	handle_mem(char **result, char const *s, char c)
{
	int	segments;
	int	i;

	i = 0;
	segments = nsegments(s, c);
	while (segments > 0)
	{
		result[i] = malloc(ft_strlen(s) * sizeof(char));
		if (!result[i])
		{
			while (i >= 0)
			{
				free(result[i]);
				i--;
			}
			free(result);
			return (0);
		}
		i++;
		segments--;
	}
	return (1);
}
/*
#include <stdio.h>

int main()
{
	char const *s = "tripouille";
	char c = ' ';
	printf("%d$\n", nsegments(s, c));
	//printf("%s$\n", ft_split(s, c)[1]);
	//printf("%s$\n", ft_split(s, c)[2]);
}
*/
