/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:34:13 by arazzok           #+#    #+#             */
/*   Updated: 2024/04/06 17:08:55 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    cast_rays(t_mlx *mlx)
{
	double  h_inter;
	double  v_inter;
	int     ray;

	ray = 0;
	mlx->ray->angle = mlx->player->angle - (mlx->player->fov_rad / 2);
	while (ray < WIDTH)
	{
		
	}
}
