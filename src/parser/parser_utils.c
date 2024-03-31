/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:06:05 by arazzok           #+#    #+#             */
/*   Updated: 2024/03/31 17:56:52 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

bool	is_valid_char(char c)
{
	if (c == '0'
		|| c == '1'
		|| c == 'N'
		|| c == 'S'
		|| c == 'W'
		|| c == 'E'
		|| c == ' '
		|| c == '\n')
		return (true);
	return (false);
}

bool	is_line_closed(char *line)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(line);
	while (line[i] == ' ' || line[i] == '\n')
		i++;
	if (line[i] != '1')
		return (false);
	i = len - 1;
	while (line[i] == ' ' || line[i] == '\n')
		i--;
	if (line[i] != '1')
		return (false);
	return (true);
}

bool	is_position_surrounded(t_map *fmap, int x, int y)
{
	int	i;
	int	j;

	if (x == 0 || x == fmap->map_height - 1
		|| y == 0 || y == (int)ft_strlen(fmap->map[x]) - 1)
		return (false);
	i = x - 1;
	while (i <= x + 1)
	{
		j = y - 1;
		while (j <= y + 1)
		{
			if (fmap->map[i][j] != '0' && fmap->map[i][j] != '1'
				&& fmap->map[i][j] != 'N' && fmap->map[i][j] != 'S'
				&& fmap->map[i][j] != 'W' && fmap->map[i][j] != 'E')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
