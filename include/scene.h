/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:02:00 by arazzok           #+#    #+#             */
/*   Updated: 2024/04/14 02:02:28 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# define TITLE "Cub3D"
# define WIDTH 1280
# define HEIGHT 720
# define TILE_SIZE 30
# define FOV 60

# include "parser.h"

typedef struct s_player
{
	int				x; // x position in pixels
	int				y; // y position in pixels
	double			angle;
	float			fov_rad; // field of view in radians
	int				rot_f; // rotation flag
	int				lr_f; // left-right flag
	int				ud_f; // up-down flag
}					t_player;

typedef struct s_ray
{
	int				id;
	double			angle;
	double			h_x_inter;
	double			h_y_inter;
	double			v_x_inter;
	double			v_y_inter;
	double			distance; // distance to the wall
	int				w_f; // wall flag
}					t_ray;

typedef struct s_texture
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
}					t_texture;

typedef struct s_mlx
{
	mlx_image_t		*img;
	mlx_t			*mlx_ptr;
	t_map			*fmap;
	t_player		*player;
	t_ray			*ray;
	t_texture		*texture;
}					t_mlx;

/* ************************************************************************** */
/*                                                                            */
/* raycasting                                                                 */
/*                                                                            */
/* ************************************************************************** */

void				cast_rays(t_mlx *mlx);
float				normalize_angle(float angle);
int					inter_check(float angle, float *inter, float *step,
						int is_horizon);
int					unit_circle(float angle, char c);
int					wall_hit(float x, float y, t_mlx *mlx);

/* ************************************************************************** */
/*                                                                            */
/* render                                                                     */
/*                                                                            */
/* ************************************************************************** */

void				render(t_mlx *mlx, int ray);
int					reverse_bytes(int c);
unsigned int		get_rgb(int r, int g, int b);
unsigned int		color_to_hexa(char *color);
void				init_put_pixel(t_mlx *mlx, int x, int y, int color);
double				get_texture_offset(t_mlx *mlx, mlx_texture_t *texture);

#endif
