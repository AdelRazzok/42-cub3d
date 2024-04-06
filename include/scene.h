/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:02:00 by arazzok           #+#    #+#             */
/*   Updated: 2024/04/06 17:01:51 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# define TITLE "Cub3D"
# define WIDTH 1900
# define HEIGHT 1080
# define TILE_SIZE 30
# define FOV 60 // Field of view
# define ROTATION_SPEED 0.045
# define PLAYER_SPEED 4

# include "MLX42.h"
# include "parser.h"

typedef struct s_player
{
	int			x; // x position in pixels
	int			y; // y position in pixels
	double		angle;
	float		fov_rad; // field of view in radians
	int			rot_f;     // rotation flag
	int			lr_f;      // left-right flag
	int			ud_f;      // up-down flag
}				t_player;

typedef struct s_ray
{
	double		angle;
	double		distance; // distance to the wall
	int			w_f; // wall flag
}				t_ray;

typedef struct s_mlx
{
	mlx_image_t	*img;
	mlx_t		*mlx_ptr;
	t_map		*fmap;
	t_player	*player;
	t_ray		*ray;
}				t_mlx;

/* ************************************************************************** */
/*                                                                            */
/* game                                                                       */
/*                                                                            */
/* ************************************************************************** */

void			game_loop(t_mlx *mlx);
void			render(void *param);
void			close_game(t_mlx *mlx);

/* ************************************************************************** */
/*                                                                            */
/* commands                                                                   */
/*                                                                            */
/* ************************************************************************** */

void			on_key_press(mlx_key_data_t keydata, void *param);

/* ************************************************************************** */
/*                                                                            */
/* moves                                                                      */
/*                                                                            */
/* ************************************************************************** */

void			handle_moves(t_mlx *mlx, double move_x, double move_y);

/* ************************************************************************** */
/*                                                                            */
/* raycasting                                                                 */
/*                                                                            */
/* ************************************************************************** */

void			cast_rays(t_mlx *mlx);

#endif
