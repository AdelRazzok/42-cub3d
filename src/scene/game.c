/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:21:32 by arazzok           #+#    #+#             */
/*   Updated: 2024/04/06 16:52:36 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_loop(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init(WIDTH, HEIGHT, TITLE, false);
	mlx_loop_hook(mlx->mlx_ptr, render, mlx);
	mlx_key_hook(mlx->mlx_ptr, on_key_press, mlx);
	mlx_loop(mlx->mlx_ptr);
}

void	render(void *param)
{
	t_mlx	*mlx;

	mlx = param;
	mlx_delete_image(mlx->mlx_ptr, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	handle_moves(mlx, 0, 0);
	cast_rays(mlx);
	mlx_image_to_window(mlx->mlx_ptr, mlx->img, 0, 0);
}

void	close_game(t_mlx *mlx)
{
	free_map(mlx->fmap);
	free_mlx(mlx);
}
