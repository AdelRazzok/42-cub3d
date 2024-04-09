/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:34:13 by arazzok           #+#    #+#             */
/*   Updated: 2024/04/09 14:01:05 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	_get_h_inter(t_mlx *mlx, float angle);
static float	_get_v_inter(t_mlx *mlx, float angle);
static float	_normalize_angle(float angle);

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
		h_inter = _get_h_inter(mlx, _normalize_angle(mlx->ray->angle));
		v_inter = _get_v_inter(mlx, _normalize_angle(mlx->ray->angle));
		if (h_inter < v_inter)
		{
			mlx->ray->distance = h_inter;
			mlx->ray->w_f = 1;
		}
		else
			mlx->ray->distance = v_inter;
		// render_wall(mlx, ray);
		ray++;
		mlx->ray->angle += (mlx->player->fov_rad / WIDTH);
	}
}

static float	_get_h_inter(t_mlx *mlx, float angle)
{
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = TILE_SIZE / tan(angle);
	y_step = TILE_SIZE;
	h_y = floor(mlx->player->y / TILE_SIZE) * TILE_SIZE;
	h_x = mlx->player->x + (h_y - mlx->player->y) / tan(angle);
	pixel = h_inter_check(angle, &h_y, &y_step);
	if ((is_y_unit_circle(angle) && x_step > 0) || (!is_y_unit_circle(angle)
			&& x_step < 0))
		x_step *= -1;
	while (wall_hit(mlx, h_x, h_y - pixel))
	{
		h_x += x_step;
		h_y += y_step;
	}
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
	v_y = mlx->player->y + (v_x - mlx->player->x) * tan(angle);
	pixel = v_inter_check(angle, &v_x, &x_step);
	if ((is_x_unit_circle(angle) && y_step > 0) || (!is_x_unit_circle(angle)
			&& y_step < 0))
		y_step *= -1;
	while (wall_hit(mlx, v_x - pixel, v_y))
	{
		v_x += x_step;
		v_y += y_step;
	}
	return (sqrt(pow(v_x - mlx->player->x, 2) + pow(v_y - mlx->player->y, 2)));
}

static float	_normalize_angle(float angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}
