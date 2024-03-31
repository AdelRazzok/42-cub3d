/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:35:27 by arazzok           #+#    #+#             */
/*   Updated: 2024/03/31 14:33:30 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*init_map(void)
{
	t_map	*fmap;

	fmap = malloc(sizeof(t_map));
	if (!fmap)
		error(ERR_MALLOC);
	fmap->map = NULL;
	fmap->map_height = 0;
	fmap->north_path = NULL;
	fmap->south_path = NULL;
	fmap->west_path = NULL;
	fmap->east_path = NULL;
	fmap->floor_color = NULL;
	fmap->ceiling_color = NULL;
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
	if (fmap->map)
		free_array(fmap->map);
	if (fmap->north_path)
		free(fmap->north_path);
	if (fmap->south_path)
		free(fmap->south_path);
	if (fmap->west_path)
		free(fmap->west_path);
	if (fmap->east_path)
		free(fmap->east_path);
	if (fmap->floor_color)
		free(fmap->floor_color);
	if (fmap->ceiling_color)
		free(fmap->ceiling_color);
	free(fmap);
}

/* ************************************************************************** */
/*                                                                            */
/* Test functions                                                             */
/*                                                                            */
/* ************************************************************************** */

void	print_map(t_map *fmap)
{
	int	i;

	i = 0;
	printf("\nPRINT T_MAP : \n");
	while (fmap->map && fmap->map[i])
	{
		printf("map[%d]: %s\n", i, fmap->map[i]);
		i++;
	}
	if (fmap->north_path)
		printf("north_path    : %s", fmap->north_path);
	if (fmap->south_path)
		printf("south_path    : %s", fmap->south_path);
	if (fmap->west_path)
		printf("west_path     : %s", fmap->west_path);
	if (fmap->east_path)
		printf("east_path     : %s", fmap->east_path);
	if (fmap->floor_color)
		printf("floor_color   : %s", fmap->floor_color);
	if (fmap->ceiling_color)
		printf("ceiling_color : %s\n", fmap->ceiling_color);
}
