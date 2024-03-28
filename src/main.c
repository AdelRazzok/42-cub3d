/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:29:37 by arazzok           #+#    #+#             */
/*   Updated: 2024/03/28 17:42:45 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"
#include "parser.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	t_map	*fmap;

	if (argc != 2)
		error(ERR_NB_ARGS);
	check_file(argv[1], ".cub");
	fmap = init_map();
	parse_map(argv[1], fmap);
	free_map(fmap);
	return (0);
}
