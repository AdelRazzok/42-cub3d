/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:16:22 by arazzok           #+#    #+#             */
/*   Updated: 2024/04/06 16:21:36 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	on_release_key(mlx_key_data_t keydata, t_mlx *mlx)
{
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		mlx->player->lr_f = 0;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		mlx->player->lr_f = 0;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		mlx->player->ud_f = 0;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		mlx->player->ud_f = 0;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		mlx->player->rot_f = 0;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		mlx->player->rot_f = 0;
}

void	on_key_press(mlx_key_data_t keydata, void *param)
{
	t_mlx	*mlx;

	mlx = param;
	if (keydata.key == MLX_KEY_ESCAPE
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		close_game(mlx);
		exit(0);
	}
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		mlx->player->lr_f = 1;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		mlx->player->lr_f = -1;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		mlx->player->ud_f = 1;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		mlx->player->ud_f = -1;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		mlx->player->rot_f = 1;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		mlx->player->rot_f = -1;
	on_release_key(keydata, mlx);
}
