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

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	free_all(char **r, int n)
{
	while (n > 0)
		free(r[--n]);
	free(r);
}

static char	**fill(char **r, char const *s, char c)
{
	int		i;
	size_t	len;

	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			r[i] = ft_substr(s, 0, len);
			if (!r[i])
				return (free_all(r, i), NULL);
			i++;
			s += len;
		}
	}
	r[i] = NULL;
	return (r);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (fill(result, s, c));
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
