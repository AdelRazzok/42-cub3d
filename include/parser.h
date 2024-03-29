/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:44:52 by arazzok           #+#    #+#             */
/*   Updated: 2024/03/29 13:34:06 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_map
{
	char	**map;
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	char	*floor_color;
	char	*ceiling_color;
	int		map_len;
}			t_map;

void		parse_map(char *path, t_map *map);

/* ************************************************************************** */
/*                                                                            */
/* parser_utils                                                               */
/*                                                                            */
/* ************************************************************************** */

void		_handle_element(char *line, t_map *fmap);
void		_handle_map(char *line, t_map *fmap);

/* ************************************************************************** */
/*                                                                            */
/* parser_utils                                                               */
/*                                                                            */
/* ************************************************************************** */

int			full_map_len(char *path);
char		**full_map_to_array(char *path);
bool		is_element(char *line);
bool		is_map_char(char *line);

#endif
