/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:44:52 by arazzok           #+#    #+#             */
/*   Updated: 2024/04/09 18:58:32 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_map
{
	char	**map;
	int		map_height;
	int		player_x;
	int		player_y;
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	char	*floor_color;
	char	*ceiling_color;
}			t_map;

/* ************************************************************************** */
/*                                                                            */
/* parser                                                                     */
/*                                                                            */
/* ************************************************************************** */

void		parse_map(char *path, t_map *map);
void		handle_element(char *line, t_map *fmap);
void		handle_map(char *line, t_map *fmap);

/* ************************************************************************** */
/*                                                                            */
/* parser_utils                                                               */
/*                                                                            */
/* ************************************************************************** */

bool		is_element(char *line);
bool		is_map_char(char *line);
bool		is_valid_char(char c);
bool		is_line_closed(char *line);
bool		is_position_surrounded(t_map *fmap, int x, int y);
bool		is_format_correct(const char *str);
void		check_start_point(t_map *fmap);

#endif
