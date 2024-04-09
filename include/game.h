/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:23:46 by arazzok           #+#    #+#             */
/*   Updated: 2024/04/09 14:25:19 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define ROTATION_SPEED 0.045
# define PLAYER_SPEED 4

/* ************************************************************************** */
/*                                                                            */
/* game                                                                       */
/*                                                                            */
/* ************************************************************************** */

void			start_game(t_mlx *mlx);
void			game_loop(void *param);
void			close_game(t_mlx *mlx);

/* ************************************************************************** */
/*                                                                            */
/* commands                                                                   */
/*                                                                            */
/* ************************************************************************** */

void			on_key_press(mlx_key_data_t keydata, void *param);
void			on_key_release(mlx_key_data_t keydata, t_mlx *mlx);

/* ************************************************************************** */
/*                                                                            */
/* moves                                                                      */
/*                                                                            */
/* ************************************************************************** */

void			handle_moves(t_mlx *mlx, double move_x, double move_y);

#endif
