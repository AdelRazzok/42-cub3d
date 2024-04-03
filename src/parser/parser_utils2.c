/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:06:00 by arazzok           #+#    #+#             */
/*   Updated: 2024/04/03 16:36:18 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_start_point(t_map *fmap)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (fmap->map[i])
	{
		j = 0;
		while (fmap->map[i][j])
		{
			if (fmap->map[i][j] == 'N' || fmap->map[i][j] == 'S'
				|| fmap->map[i][j] == 'W' || fmap->map[i][j] == 'E')
			{
				fmap->player_x = j;
				fmap->player_y = i;
				count++;
			}
			j++;
		}
		i++;
	}
	if (count != 1)
		free_and_error(ERR_INVALID_MAP, fmap);
}
