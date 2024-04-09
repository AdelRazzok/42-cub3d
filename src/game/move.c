/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:43:41 by arazzok           #+#    #+#             */
/*   Updated: 2024/04/06 16:52:15 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	_move_player(t_mlx *mlx, double move_x, double move_y);
static void	_rotate_player(t_mlx *mlx, int i);

void	handle_moves(t_mlx *mlx, double move_x, double move_y)
{
	if (mlx->player->rot_f == 1)
		_rotate_player(mlx, 1);
	if (mlx->player->rot_f == -1)
		_rotate_player(mlx, 0);
	if (mlx->player->lr_f == 1)
	{
		move_x = -sin(mlx->player->angle) * PLAYER_SPEED;
		move_y = cos(mlx->player->angle) * PLAYER_SPEED;
	}
	if (mlx->player->lr_f == -1)
	{
		move_x = sin(mlx->player->angle) * PLAYER_SPEED;
		move_y = -cos(mlx->player->angle) * PLAYER_SPEED;
	}
	if (mlx->player->ud_f == 1)
	{
		move_x = sin(mlx->player->angle) * PLAYER_SPEED;
		move_y = cos(mlx->player->angle) * PLAYER_SPEED;
	}
	if (mlx->player->ud_f == -1)
	{
		move_x = -sin(mlx->player->angle) * PLAYER_SPEED;
		move_y = -cos(mlx->player->angle) * PLAYER_SPEED;
	}
	_move_player(mlx, move_x, move_y);
}

static void	_move_player(t_mlx *mlx, double move_x, double move_y)
{
	int	map_x;
	int	map_y;
	int	new_x;
	int	new_y;

	new_x = roundf(mlx->player->x + move_x);
	new_y = roundf(mlx->player->y + move_y);
	map_x = new_x / TILE_SIZE;
	map_y = new_y / TILE_SIZE;
	if (mlx->fmap->map[map_y][map_x] != '1'
		&& (mlx->fmap->map[map_y][mlx->player->x / TILE_SIZE] != '1'
			&& mlx->fmap->map[mlx->player->y / TILE_SIZE][map_x] != '1'))
	{
		mlx->player->x = new_x;
		mlx->player->y = new_y;
	}
}

static void	_rotate_player(t_mlx *mlx, int i)
{
	if (i == 1)
	{
		mlx->player->angle += ROTATION_SPEED;
		if (mlx->player->angle > 2 * M_PI)
			mlx->player->angle -= 2 * M_PI;
	}
	else
	{
		mlx->player->angle -= ROTATION_SPEED;
		if (mlx->player->angle < 0)
			mlx->player->angle += 2 * M_PI;
	}
}
