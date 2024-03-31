/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:57:07 by arazzok           #+#    #+#             */
/*   Updated: 2024/03/31 15:18:55 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	_handle_color(char *line, t_map *fmap);
static void	_check_duplicate(char *line, t_map *fmap);
static void	_skip_id_and_spaces(char **line);

void	handle_element(char *line, t_map *fmap)
{
	_check_duplicate(line, fmap);
	if (!ft_strncmp(line, "NO", 2))
	{
		_skip_id_and_spaces(&line);
		fmap->north_path = ft_strdup(line);
	}
	else if (!ft_strncmp(line, "SO", 2))
	{
		_skip_id_and_spaces(&line);
		fmap->south_path = ft_strdup(line);
	}
	else if (!ft_strncmp(line, "WE", 2))
	{
		_skip_id_and_spaces(&line);
		fmap->west_path = ft_strdup(line);
	}
	else if (!ft_strncmp(line, "EA", 2))
	{
		_skip_id_and_spaces(&line);
		fmap->east_path = ft_strdup(line);
	}
	else
		_handle_color(line, fmap);
}

void	handle_map(char *line, t_map *fmap)
{
	char	**tmp;

	fmap->map_height++;
	if (!fmap->map)
	{
		fmap->map = (char **)malloc(sizeof(char *) * 2);
		fmap->map[0] = ft_strdup(line);
		fmap->map[1] = NULL;
		return ;
	}
	tmp = arrdup(fmap->map, fmap->map_height);
	free_array(fmap->map);
	fmap->map = tmp;
	fmap->map[fmap->map_height - 1] = ft_strdup(line);
	fmap->map[fmap->map_height] = NULL;
}

static void	_handle_color(char *line, t_map *fmap)
{
	if (!ft_strncmp(line, "F", 1))
	{
		line++;
		skip_spaces(&line);
		fmap->floor_color = ft_strdup(line);
	}
	else if (!ft_strncmp(line, "C", 1))
	{
		line++;
		skip_spaces(&line);
		fmap->ceiling_color = ft_strdup(line);
	}
}

static void	_check_duplicate(char *line, t_map *fmap)
{
	if ((!ft_strncmp(line, "NO", 2) && fmap->north_path)
		|| (!ft_strncmp(line, "SO", 2) && fmap->south_path)
		|| (!ft_strncmp(line, "WE", 2) && fmap->west_path)
		|| (!ft_strncmp(line, "EA", 2) && fmap->east_path)
		|| (!ft_strncmp(line, "F", 1) && fmap->floor_color)
		|| (!ft_strncmp(line, "C", 1) && fmap->ceiling_color))
	{
		free(line);
		free_and_error(ERR_DUPLICATE, fmap);
	}
}

static void	_skip_id_and_spaces(char **line)
{
	*(line) += 2;
	skip_spaces(line);
}
