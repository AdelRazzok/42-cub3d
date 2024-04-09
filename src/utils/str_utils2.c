/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:34:50 by arazzok           #+#    #+#             */
/*   Updated: 2024/04/09 18:44:42 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	dup = malloc(len * sizeof(*dup) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

void	skip_spaces(char **str)
{
	while (**str == ' ')
		(*str)++;
}

char	**arrdup(char **src, int size)
{
	char	**array;
	int		i;

	array = malloc(sizeof(char *) * (size + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (src[i] && i < size)
	{
		array[i] = ft_strdup(src[i]);
		i++;
	}
	array[i] = NULL;
	return (array);
}

int	ft_atoi(const char *str)
{
	int	value;
	int	sign;

	value = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		++str;
	if (*str == '-')
	{
		++str;
		sign = -sign;
	}
	else if (*str == '+')
		++str;
	while (*str >= '0' && *str <= '9')
		value = 10 * value + (*str++) - '0';
	if (value * sign < 0)
		return (0);
	if (value * sign > 255)
		return (255);
	return (value * sign);
}
