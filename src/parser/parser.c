/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:20:43 by arazzok           #+#    #+#             */
/*   Updated: 2024/03/27 14:23:22 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include "utils.h"

t_element	*get_elements(char *path)
{
	t_element	*element = NULL;
    char        *line;
	int			fd;

	fd = open(path, O_RDONLY);
    line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
        free(line);
        line = get_next_line(fd);
	}
	close(fd);
    return (element);
}
