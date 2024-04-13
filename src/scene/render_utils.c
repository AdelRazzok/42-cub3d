/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:17:21 by arazzok           #+#    #+#             */
/*   Updated: 2024/04/13 15:54:19 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	reverse_bytes(int c)
{
	unsigned int	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}

unsigned int	get_rgb(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 0xFF);
}

unsigned int	color_to_hexa(char *color)
{
	int				i;
	unsigned int	hexa;
	char			**split;

	i = 0;
	hexa = 0;
	split = ft_split(color, ',');
	while (split[i])
		i++;
	hexa = get_rgb(ft_atoi(split[0]), ft_atoi(split[1]), ft_atoi(split[2]));
	free_array(split);
	return (hexa);
}

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

double	get_texture_offset(t_mlx *mlx, mlx_texture_t *texture)
{
	double	offset;

	if (mlx->ray->w_f == 1)
		offset = (int)fmodf((mlx->ray->h_x_inter * (texture->width
						/ TILE_SIZE)), texture->width);
	else
		offset = (int)fmodf((mlx->ray->v_y_inter * (texture->width
						/ TILE_SIZE)), texture->width);
	return (offset);
}
