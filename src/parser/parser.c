/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:20:43 by arazzok           #+#    #+#             */
/*   Updated: 2024/03/31 18:09:42 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	_check_line(char *line, t_map *fmap);
static void	_process_line(char *line, t_map *fmap);
static void	_check_missing_elements(t_map *fmap);
static void	_check_map(t_map *fmap);

void	parse_map(char *path, t_map *fmap)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		_check_line(line, fmap);
		_process_line(line, fmap);
		free(line);
		line = get_next_line(fd);
	}
	_check_missing_elements(fmap);
	_check_map(fmap);
	close(fd);
	free(line);
}

static void	_check_line(char *line, t_map *fmap)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] < 32 || line[i] > 126) && line[i] != '\n')
			free_and_error(ERR_INVALID_MAP, fmap);
		i++;
	}
}

static void	_process_line(char *line, t_map *fmap)
{
	char	*tmp;

	tmp = line;
	if (*line == '\0' || *line == '\n')
		return ;
	skip_spaces(&line);
	if (is_element(line))
	{
		line = tmp;
		skip_spaces(&line);
		handle_element(line, fmap);
	}
	else if (is_map_char(line))
	{
		line = tmp;
		handle_map(line, fmap);
	}
}

static void	_check_missing_elements(t_map *fmap)
{
	if (!fmap->north_path
		|| !fmap->south_path
		|| !fmap->west_path
		|| !fmap->east_path
		|| !fmap->floor_color
		|| !fmap->ceiling_color)
		free_and_error(ERR_MISSSING_ELEMENT, fmap);
}

static void	_check_map(t_map *fmap)
{
	int	i;
	int	j;

	check_start_point(fmap);
	i = 0;
	while (i < fmap->map_height)
	{
		if (!is_line_closed(fmap->map[i]))
			free_and_error(ERR_INVALID_MAP, fmap);
		j = 0;
		while (j < (int)ft_strlen(fmap->map[i]))
		{
			if (!is_valid_char(fmap->map[i][j]))
				free_and_error(ERR_INVALID_MAP, fmap);
			if (fmap->map[i][j] == '0' || fmap->map[i][j] == 'N'
				|| fmap->map[i][j] == 'S' || fmap->map[i][j] == 'W'
				|| fmap->map[i][j] == 'E')
			{
				if (!is_position_surrounded(fmap, i, j))
					free_and_error(ERR_INVALID_MAP, fmap);
			}
			j++;
		}
		i++;
	}
}
