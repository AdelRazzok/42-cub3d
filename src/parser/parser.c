/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:20:43 by arazzok           #+#    #+#             */
/*   Updated: 2024/03/28 18:27:10 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include "utils.h"

static int	_process_line(char *line, t_map *fmap);
static void	_handle_element(char *line, t_map *fmap);

void	parse_map(char *path, t_map *fmap)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		_process_line(line, fmap);
		free(line);
		line = get_next_line(fd);
	}
	// TODO : Fonction de verification de la structure map, s'il en ùmanque un -> erreur
	// TODO : Vérification de la map
	close(fd);
	free(line);
}

static int	_process_line(char *line, t_map *fmap)
{
	if (*line == '\0' || *line == '\n')
		return (printf("Ligne vide\n"));
	while (*line == ' ')
		line++;
	if (!is_element(line))
		return (printf("Pas un element\n"), 1);
	else
		_handle_element(line, fmap);

	// 1.6. A la première ligne qui commence par 1, 0, N, S, W ou E, on sait que c'est le début de la map
	if (is_map_char(*line))
	{
		// TODO: parsing de la map
	}
}

static void _handle_element(char *line, t_map *fmap)
{

	// ! Si l'element est deja present dans la structure -> erreur !

	(void)fmap;
	if (!ft_strcmp(line, "NO"))
		printf("NO\n");
	else if (!ft_strcmp(line, "SO"))
		printf("SO\n");
	else if (!ft_strcmp(line, "WE"))
		printf("WE\n");
	else if (!ft_strcmp(line, "EA"))
		printf("EA\n");
	else if (!ft_strcmp(line, "F"))
		printf("F\n");
	else if (!ft_strcmp(line, "C"))
		printf("C\n");
}
