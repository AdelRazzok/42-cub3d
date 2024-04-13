/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:16:35 by arazzok           #+#    #+#             */
/*   Updated: 2024/04/13 16:38:38 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void				_draw_wall(t_mlx *mlx, int t_pixel, int b_pixel,
							double wall_height);
static void				_draw_floor_and_ceiling(t_mlx *mlx, int ray,
							int t_pixel, int b_pixel);
static mlx_texture_t	*get_texture(t_mlx *mlx);

void	render(t_mlx *mlx, int ray)
{
	double	wall_height;
	double	b_pixel;
	double	t_pixel;

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
	mlx->ray->id = ray;
	_draw_wall(mlx, t_pixel, b_pixel, wall_height);
	_draw_floor_and_ceiling(mlx, ray, t_pixel, b_pixel);
}

static void	_draw_wall(t_mlx *mlx, int t_pixel, int b_pixel, double wall_height)
{
	mlx_texture_t	*texture;
	uint32_t		*text_pixels;
	double			x_offset;
	double			y_offset;
	double			scalling_factor;

	texture = get_texture(mlx);
	text_pixels = (uint32_t *)texture->pixels;
	scalling_factor = (double)texture->height / wall_height;
	x_offset = get_texture_offset(mlx, texture);
	y_offset = (t_pixel - (HEIGHT / 2) + (wall_height / 2)) * scalling_factor;
	if (y_offset < 0)
		y_offset = 0;
	while (t_pixel < b_pixel)
	{
		init_put_pixel(mlx, mlx->ray->id, t_pixel,
			reverse_bytes(text_pixels[(int)y_offset * texture->width
				+ (int)x_offset]));
		y_offset += scalling_factor;
		t_pixel++;
	}
}

static void	_draw_floor_and_ceiling(t_mlx *mlx, int ray, int t_pixel,
		int b_pixel)
{
	int	i;

	i = b_pixel;
	while (i < HEIGHT)
		init_put_pixel(mlx, ray, i++, color_to_hexa(mlx->fmap->floor_color));
	i = 0;
	while (i < t_pixel)
		init_put_pixel(mlx, ray, i++, color_to_hexa(mlx->fmap->ceiling_color));
}

static mlx_texture_t	*get_texture(t_mlx *mlx)
{
	mlx->ray->angle = normalize_angle(mlx->ray->angle);
	if (mlx->ray->w_f == 0)
	{
		if (is_y_unit_circle(mlx->ray->angle))
			return (mlx->texture->east);
		else
			return (mlx->texture->west);
	}
	else
	{
		if (is_x_unit_circle(mlx->ray->angle))
			return (mlx->texture->south);
		else
			return (mlx->texture->north);
	}
}
