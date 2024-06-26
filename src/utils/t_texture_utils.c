/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_texture_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:32:23 by arazzok           #+#    #+#             */
/*   Updated: 2024/04/14 13:04:27 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*trim_end(char *line);
void		free_texture(t_texture *texture);

t_texture	*init_texture(t_map *fmap, t_mlx *mlx)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	if (!texture)
		return (NULL);
	texture->north = mlx_load_png(trim_end(fmap->north_path));
	texture->south = mlx_load_png(trim_end(fmap->south_path));
	texture->east = mlx_load_png(trim_end(fmap->east_path));
	texture->west = mlx_load_png(trim_end(fmap->west_path));
	if (!texture->north || !texture->south || !texture->east || !texture->west)
	{
		free_texture(texture);
		free(mlx->player);
		free(mlx->ray);
		free(mlx);
		free_and_error(ERR_TEXTURE, fmap);
	}
	return (texture);
}

void	free_texture(t_texture *texture)
{
	if (texture->north)
		mlx_delete_texture(texture->north);
	if (texture->south)
		mlx_delete_texture(texture->south);
	if (texture->east)
		mlx_delete_texture(texture->east);
	if (texture->west)
		mlx_delete_texture(texture->west);
	free(texture);
}

char	*trim_end(char *line)
{
	int	i;

	i = 0;
	while (line[i] && !(line[i] >= 9 && line[i] <= 13) && line[i] != ' ')
		i++;
	line[i] = '\0';
	return (line);
}
