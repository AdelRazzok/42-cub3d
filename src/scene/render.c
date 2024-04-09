/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:16:35 by arazzok           #+#    #+#             */
/*   Updated: 2024/04/09 18:59:02 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	if (x < 0)
		return ;
	else if (x >= WIDTH)
		return ;
	if (y < 0)
		return ;
	else if (y >= HEIGHT)
		return ;
	mlx_put_pixel(mlx->img, x, y, color);
}

void	draw_floor_and_ceiling(t_mlx *mlx, int ray, int t_pixel, int b_pixel)
{
	int	i;

	i = b_pixel;
	while (i < HEIGHT)
		init_put_pixel(mlx, ray, i++, 0x89CFF3FF);
	i = 0;
	while (i < t_pixel)
		init_put_pixel(mlx, ray, i++, 0x89CFF3FF);
}

void	render(t_mlx *mlx, int ray)
{
	double	wall_height;
	double	b_pixel;
	double	t_pixel;

	// fisheye fix
	mlx->ray->distance *= cos(normalize_angle(mlx->ray->angle
				- mlx->player->angle));
	wall_height = (TILE_SIZE / mlx->ray->distance) * ((WIDTH / 2)
			/ tan(mlx->player->fov_rad / 2));
	b_pixel = (HEIGHT / 2) + (wall_height / 2);
	t_pixel = (HEIGHT / 2) - (wall_height / 2);
	if (b_pixel > HEIGHT)
		b_pixel = HEIGHT;
	if (t_pixel < 0)
		t_pixel = 0;
	draw_floor_and_ceiling(mlx, ray, t_pixel, b_pixel);
}
