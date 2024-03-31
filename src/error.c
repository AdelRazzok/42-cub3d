/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:50:15 by arazzok           #+#    #+#             */
/*   Updated: 2024/03/31 15:20:29 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	_print_error(const char *msg);

void	error(t_error error_code)
{
	if (error_code == ERR_NB_ARGS)
		_print_error(MSG_NB_ARGS);
	else if (error_code == ERR_EXTENSION)
		_print_error(MSG_EXTENSION);
	else if (error_code == ERR_MALLOC)
		_print_error(MSG_MALLOC);
	else if (error_code == ERR_FILE)
		_print_error(MSG_FILE);
	else if (error_code == ERR_DUPLICATE)
		_print_error(MSG_DUPLICATE);
	else if (error_code == ERR_MISSSING_ELEMENT)
		_print_error(MSG_MISSSING_ELEMENT);
	else if (error_code == ERR_INVALID_MAP)
		_print_error(MSG_INVLID_MAP);
	exit(1);
}

void	check_file(const char *path, const char *extension)
{
	int	fd;
	int	path_len;
	int	extension_len;

	path_len = ft_strlen(path);
	extension_len = ft_strlen(extension);
	if (path_len < extension_len
		|| ft_strcmp(path + path_len - extension_len, extension) != 0)
		error(ERR_EXTENSION);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error(ERR_FILE);
	close(fd);
}

static void	_print_error(const char *msg)
{
	int	msg_len;

	msg_len = ft_strlen(msg);
	write(STDERR_FILENO, msg, msg_len);
}

void	free_and_error(t_error error_code, t_map *fmap)
{
	free_map(fmap);
	error(error_code);
}
