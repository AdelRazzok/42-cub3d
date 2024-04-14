/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:08:46 by arazzok           #+#    #+#             */
/*   Updated: 2024/04/14 01:58:07 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_player	*_init_player(t_map *fmap);
static t_ray	*_init_ray(void);
static double	_get_angle(t_map *fmap);

t_mlx	*init_mlx(t_map *fmap)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		free_and_error(ERR_MALLOC, fmap);
	mlx->img = NULL;
	mlx->mlx_ptr = NULL;
	mlx->fmap = fmap;
	mlx->player = _init_player(mlx->fmap);
	mlx->ray = _init_ray();
	mlx->texture = init_texture(mlx->fmap);
	return (mlx);
}

void	free_mlx(t_mlx *mlx)
{
	if (mlx->player)
		free(mlx->player);
	if (mlx->ray)
		free(mlx->ray);
	if (mlx->texture)
		free_texture(mlx->texture);
	if (mlx->img)
		mlx_delete_image(mlx->mlx_ptr, mlx->img);
	mlx_close_window(mlx->mlx_ptr);
	mlx_terminate(mlx->mlx_ptr);
	free(mlx);
}

static t_player	*_init_player(t_map *fmap)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->x = fmap->player_x * TILE_SIZE + TILE_SIZE / 2;
	player->y = fmap->player_y * TILE_SIZE + TILE_SIZE / 2;
	player->angle = _get_angle(fmap);
	player->fov_rad = (FOV * M_PI) / 180;
	player->rot_f = 0;
	player->lr_f = 0;
	player->ud_f = 0;
	return (player);
}

static t_ray	*_init_ray(void)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->id = 0;
	ray->angle = 0;
	ray->h_x_inter = 0;
	ray->h_y_inter = 0;
	ray->v_x_inter = 0;
	ray->v_y_inter = 0;
	ray->distance = 0;
	ray->w_f = 0;
	return (ray);
}

static double	_get_angle(t_map *fmap)
{
	char	dir;

	dir = fmap->map[fmap->player_y][fmap->player_x];
	if (dir == 'N')
		return (3 * M_PI / 2);
	else if (dir == 'S')
		return (M_PI / 2);
	else if (dir == 'W')
		return (M_PI);
	else
		return (0);
}
