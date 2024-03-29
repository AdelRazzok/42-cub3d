/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:06:05 by arazzok           #+#    #+#             */
/*   Updated: 2024/03/29 12:17:06 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	full_map_len(char *path)
{
	char	*line;
	int		len;
	int		fd;

	len = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (len);
}

char	**full_map_to_array(char *path)
{
	int		map_len;
	char	*line;
	char	**map;
	int		fd;
	int		i;

	map_len = full_map_len(path);
	map = malloc(sizeof(char *) * (map_len + 1));
	fd = open(path, O_RDONLY);
	i = 0;
	while (i < map_len)
	{
		line = get_next_line(fd);
		map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

bool	is_element(char *line)
{
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
		|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2)
		|| !ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1))
		return (true);
	return (false);
}

bool	is_map_char(char *line)
{
	if (!ft_strncmp(line, "1", 1) || !ft_strncmp(line, "0", 1))
		return (true);
	if (!ft_strncmp(line, "N", 1) && ft_strncmp(line, "NO", 2))
		return (true);
	if (!ft_strncmp(line, "S", 1) && ft_strncmp(line, "SO", 2))
		return (true);
	if (!ft_strncmp(line, "W", 1) && ft_strncmp(line, "WE", 2))
		return (true);
	if (!ft_strncmp(line, "E", 1) && ft_strncmp(line, "EA", 2))
		return (true);
	return (false);
}
