/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:21:32 by arazzok           #+#    #+#             */
/*   Updated: 2024/04/03 17:57:30 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_loop(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init(WIDTH, HEIGHT, TITLE, false);
	mlx_loop_hook(mlx->mlx_ptr, render, mlx);
	mlx_key_hook(mlx->mlx_ptr, &mlx_key, mlx);
	mlx_loop(mlx->mlx_ptr);
}

void	render(void *param)
{
	t_mlx	*mlx;

	mlx = param;
	mlx_delete_image(mlx->mlx_ptr, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	// hook the player
	// cast rays
	mlx_image_to_window(mlx->mlx_ptr, mlx->img, 0, 0);
}
