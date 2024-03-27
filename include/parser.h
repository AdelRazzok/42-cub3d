/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:44:52 by arazzok           #+#    #+#             */
/*   Updated: 2024/03/27 17:22:07 by arazzok          ###   ########.fr       */
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
}			t_map;

void		parse(char *path, t_map *map);

/* ************************************************************************** */
/*                                                                            */
/* parser_utils                                                               */
/*                                                                            */
/* ************************************************************************** */

int			full_map_len(char *path);
char		**full_map_to_array(char *path);

#endif
