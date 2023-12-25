/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:56:44 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/25 20:56:25 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	wordscount(char const *s, char c)
{
	size_t	i;
	size_t	wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			wc++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (wc);
}

static char	*getword(size_t *i, char const *s, char c)
{
	size_t	j;
	size_t	currwordsize;
	size_t	tpos;
	char	*res;

	j = 0;
	while (s[*i] && s[*i] == c)
		(*i)++;
	tpos = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	currwordsize = *i - tpos;
	res = (char *)malloc((currwordsize + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (tpos + j < *i)
	{
		res[j] = s[tpos + j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

static char	**freemem(char **str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	j;
	size_t	wc;
	size_t	i;
	char	**res;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	wc = wordscount(s, c);
	res = (char **)malloc((wc + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (j < wc)
	{
		res[j] = getword(&i, s, c);
		if (!res[j])
			return (freemem(res));
		j++;
	}
	res[wc] = NULL;
	return (res);
}
