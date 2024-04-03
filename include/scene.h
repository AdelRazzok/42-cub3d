/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:02:00 by arazzok           #+#    #+#             */
/*   Updated: 2024/04/03 17:40:48 by arazzok          ###   ########.fr       */
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
	int x; // x position in pixels
	int y; // y position in pixels
	double		angle;
	float fov_rad; // field of view in radians
}				t_player;

typedef struct s_ray
{
	double		angle;
	double distance; // distance to the wall
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

/* ************************************************************************** */
/*                                                                            */
/* commands                                                                   */
/*                                                                            */
/* ************************************************************************** */

void			ft_hook(void *param);

#endif
