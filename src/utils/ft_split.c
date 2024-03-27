/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:23:21 by arazzok           #+#    #+#             */
/*   Updated: 2024/03/27 13:39:53 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils.h"

static size_t	_ft_countwords(char const *s, char c);
static char		*_ft_getword(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	nb_word;
	size_t	i;

	nb_word = _ft_countwords(s, c);
	res = malloc(sizeof(*res) * (nb_word + 1));
	if (!s || !res)
		return (NULL);
	i = 0;
	while (i < nb_word)
	{
		while (*s && *s == c)
			s++;
		res[i] = _ft_getword(s, c);
		if (!res[i])
			return (NULL);
		s += ft_strlen(res[i]);
		i++;
	}
	res[nb_word] = NULL;
	return (res);
}

static size_t	_ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*_ft_getword(char const *s, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = ft_substr(s, 0, i);
	if (!word)
		return (NULL);
	return (word);
}
