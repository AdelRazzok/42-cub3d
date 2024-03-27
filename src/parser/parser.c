/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:20:43 by arazzok           #+#    #+#             */
/*   Updated: 2024/03/27 17:49:04 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include "utils.h"

void	print_map_array(char **map_array);

void	parse(char *path, t_map *fmap)
{
	char	**map_array;

	map_array = full_map_to_array(path);
	check_map(map_array);
}

static void	check_map(char **map_array)
{
	// ? Partir de la fin de la map ?

	// 1. Boucler sur la map (jusqu'a ligne vide)
	// 2. Copier les lignes dans la struct t_map.map
	// 3. Apres la ligne vide, recuperer les elements dans la struct t_map
	// 4. Verifier la map
	// 5. Verifier que tous les elements sont presents
	// 6. Verifier que les elements sont valides
}

/* ************************************************************************** */
/*                                                                            */
/* Test func                                                                  */
/*                                                                            */
/* ************************************************************************** */

void	print_map_array(char **map_array)
{
	int	i;

	i = 0;
	while (map_array[i])
	{
		printf("%s\n", map_array[i]);
		i++;
	}
}
