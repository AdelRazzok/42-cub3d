/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:34:13 by arazzok           #+#    #+#             */
/*   Updated: 2024/04/14 01:56:45 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float			normalize_angle(float angle);
static float	_get_h_inter(t_mlx *mlx, float angle);
static float	_get_v_inter(t_mlx *mlx, float angle);

void	cast_rays(t_mlx *mlx)
{
	double	h_inter;
	double	v_inter;
	int		ray;

	ray = 0;
	mlx->ray->angle = mlx->player->angle - (mlx->player->fov_rad / 2);
	while (ray < WIDTH)
	{
		mlx->ray->w_f = 0;
		h_inter = _get_h_inter(mlx, normalize_angle(mlx->ray->angle));
		v_inter = _get_v_inter(mlx, normalize_angle(mlx->ray->angle));
		if (v_inter <= h_inter)
			mlx->ray->distance = v_inter;
		else
		{
			mlx->ray->distance = h_inter;
			mlx->ray->w_f = 1;
		}
		render(mlx, ray);
		ray++;
		mlx->ray->angle += (mlx->player->fov_rad / WIDTH);
	}
}

float	normalize_angle(float angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

static float	_get_h_inter(t_mlx *mlx, float angle)
{
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;
	int		pixel;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angle);
	h_y = floor(mlx->player->y / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angle, &h_y, &y_step, 1);
	h_x = mlx->player->x + (h_y - mlx->player->y) / tan(angle);
	if ((unit_circle(angle, 'y') && x_step > 0)
		|| (!unit_circle(angle, 'y') && x_step < 0))
		x_step *= -1;
	while (wall_hit(h_x, h_y - pixel, mlx))
	{
		h_x += x_step;
		h_y += y_step;
	}
	mlx->ray->h_x_inter = h_x;
	mlx->ray->h_y_inter = h_y;
	return (sqrt(pow(h_x - mlx->player->x, 2) + pow(h_y - mlx->player->y, 2)));
}

static float	_get_v_inter(t_mlx *mlx, float angle)
{
	float	v_x;
	float	v_y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(angle);
	v_x = floor(mlx->player->x / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angle, &v_x, &x_step, 0);
	v_y = mlx->player->y + (v_x - mlx->player->x) * tan(angle);
	if ((unit_circle(angle, 'x') && y_step < 0)
		|| (!unit_circle(angle, 'x') && y_step > 0))
		y_step *= -1;
	while (wall_hit(v_x - pixel, v_y, mlx))
	{
		v_x += x_step;
		v_y += y_step;
	}
	mlx->ray->v_x_inter = v_x;
	mlx->ray->v_y_inter = v_y;
	return (sqrt(pow(v_x - mlx->player->x, 2) + pow(v_y - mlx->player->y, 2)));
}
