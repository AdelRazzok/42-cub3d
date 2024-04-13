/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:20:31 by arazzok           #+#    #+#             */
/*   Updated: 2024/04/13 14:48:13 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_x_unit_circle(float angle)
{
	if (angle > 0 && angle < M_PI)
		return (1);
	return (0);
}

int	is_y_unit_circle(float angle)
{
	if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
		return (1);
	return (0);
}

int	h_inter_check(float angle, float *inter, float *step)
{
	if (is_x_unit_circle(angle))
	{
		*inter += TILE_SIZE;
		return (-1);
	}
	*step *= -1;
	return (1);
}

int	v_inter_check(float angle, float *inter, float *step)
{
	if (is_y_unit_circle(angle))
	{
		*inter += TILE_SIZE;
		return (-1);
	}
	*step *= -1;
	return (1);
}

int	wall_hit(t_mlx *mlx, float x, float y)
{
	int	map_x;
	int	map_y;

	if (x < 0 || y < 0)
		return (0);
	map_x = floor(x / TILE_SIZE);
	map_y = floor(y / TILE_SIZE);
	if (map_y >= mlx->fmap->map_height) // ! no regular width
		return (0);
	if (mlx->fmap->map[map_y] && map_x <= (int)ft_strlen(mlx->fmap->map[map_y]))
		if (mlx->fmap->map[map_y][map_x] == '1')
			return (0);
	return (1);
}
