/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:35:27 by arazzok           #+#    #+#             */
/*   Updated: 2024/03/27 17:27:09 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"
#include "parser.h"

t_map	*init_map(void)
{
	t_map	*fmap;

	fmap = malloc(sizeof(t_map));
	if (!fmap)
		error(ERR_MALLOC);
	fmap->map = NULL;
	fmap->north_path = NULL;
	fmap->south_path = NULL;
	fmap->west_path = NULL;
	fmap->east_path = NULL;
	fmap->floor_color = 0;
	fmap->ceiling_color = 0;
	return (fmap);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_map(t_map *fmap)
{
	free_array(fmap->map);
	free(fmap->north_path);
	free(fmap->south_path);
	free(fmap->west_path);
	free(fmap->east_path);
	free(fmap);
}
