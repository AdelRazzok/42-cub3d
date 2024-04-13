/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:29:37 by arazzok           #+#    #+#             */
/*   Updated: 2024/04/13 14:28:58 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_map	*fmap;
	t_mlx	*mlx;

	if (argc != 2)
		error(ERR_NB_ARGS);
	if (HEIGHT > 1440 || WIDTH > 2560 || FOV >= 180 || FOV <= 0)
		error(ERR_RESOLUTION);
	check_file(argv[1], ".cub");
	fmap = init_map();
	parse_map(argv[1], fmap);
	print_map(fmap);
	mlx = init_mlx(fmap);
	start_game(mlx);
	close_game(mlx);
	return (0);
}
