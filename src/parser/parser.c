/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:20:43 by arazzok           #+#    #+#             */
/*   Updated: 2024/03/30 13:28:11 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	_process_line(char *line, t_map *fmap);
static void _check_missing_elements(t_map *fmap);

void	parse_map(char *path, t_map *fmap)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		_process_line(line, fmap);
		free(line);
		line = get_next_line(fd);
	}
	_check_missing_elements(fmap);
	// TODO : Vérification de la map
	close(fd);
	free(line);
}

static void	_process_line(char *line, t_map *fmap)
{
	char *tmp;

	tmp = line;
	if (*line == '\0' || *line == '\n')
		return ;
	skip_spaces(&line);
	if (is_element(line))
	{
		line = tmp;
		skip_spaces(&line);
		_handle_element(line, fmap);
	}
	else if (is_map_char(line))
	{
		line = tmp;
		_handle_map(line, fmap);
	}
}

static void _check_missing_elements(t_map *fmap)
{
	if (!fmap->north_path
		|| !fmap->south_path
		|| !fmap->west_path
		|| !fmap->east_path
		|| !fmap->floor_color
		|| !fmap->ceiling_color)
		free_and_error(ERR_MISSSING_ELEMENT, fmap);
}
