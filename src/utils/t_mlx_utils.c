/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:08:46 by arazzok           #+#    #+#             */
/*   Updated: 2024/04/03 17:53:20 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_mlx	*init_mlx(t_map *fmap)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		free_and_error(ERR_MALLOC, fmap);
	mlx->mlx_ptr = NULL;
	mlx->img = NULL;
	mlx->fmap = fmap;
	mlx->player = init_player(mlx->fmap);
	mlx->ray = malloc(sizeof(t_ray));
	return (mlx);
}

t_player	*init_player(t_map *fmap)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->x = fmap->player_x * TILE_SIZE + TILE_SIZE / 2;
	player->y = fmap->player_y * TILE_SIZE + TILE_SIZE / 2;
	player->angle = M_PI;
	player->fov_rad = (FOV * M_PI) / 180;
	return (player);
}

void	free_mlx(t_mlx *mlx)
{
	if (mlx->ray)
		free(mlx->ray);
	if (mlx->player)
		free(mlx->player);
	if (mlx->img)
		mlx_delete_image(mlx->mlx_ptr, mlx->img);
	if (mlx->mlx_ptr)
		mlx_terminate(mlx->mlx_ptr);
	free(mlx);
}
