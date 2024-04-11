/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:07:26 by arazzok           #+#    #+#             */
/*   Updated: 2024/04/11 13:25:42 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	_check_color_len(char **color, t_map *fmap);
static bool	_is_format_correct(const char *str);
static bool	_is_color_char(const char c);

void	check_colors(t_map *fmap)
{
	char	**color;

	if (!_is_format_correct(fmap->floor_color)
		|| !_is_format_correct(fmap->ceiling_color))
		free_and_error(ERR_WRONG_COLOR, fmap);
	color = ft_split(fmap->floor_color, ',');
	_check_color_len(color, fmap);
	free_array(color);
	color = ft_split(fmap->ceiling_color, ',');
	_check_color_len(color, fmap);
	free_array(color);
}

static void	_check_color_len(char **color, t_map *fmap)
{
	int	i;

	i = 0;
	while (color[i] && color[i][0] != '\n')
		i++;
	if (i != 3)
	{
		free_array(color);
		free_and_error(ERR_WRONG_COLOR, fmap);
	}
}

static bool	_is_format_correct(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (false);
	while (str[i])
	{
		if (!_is_color_char(str[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	_is_color_char(const char c)
{
	if ((c >= '0' && c <= '9') || c == ',' || c == '\n')
		return (true);
	return (false);
}
