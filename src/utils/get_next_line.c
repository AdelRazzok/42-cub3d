/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:06:56 by arazzok           #+#    #+#             */
/*   Updated: 2024/03/29 12:17:22 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*_preprocess_buffer(char *buffer);
static void	_post_process_buffer_then_append(char **line_ptr, char *buffer);
static char	*_get_next_line(int fd, char *buffer);

char	*get_next_line(int fd)
{
	static char	tails[FD_LIMIT][BUFFER_SIZE + 1] = {0};
	char		*line;

	line = _get_next_line(fd, tails[fd]);
	if (line == NULL)
		return (NULL);
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	return (line);
}

static char	*_preprocess_buffer(char *buffer)
{
	size_t	i;
	char	*line;

	i = 0;
	line = ft_strchr(buffer, '\n');
	if (line == NULL)
		line = ft_strchr(buffer, '\0');
	i = line - buffer + (*line == '\n');
	line = (char *)malloc(i + 1);
	if (line == NULL)
		return (NULL);
	ft_memcpy(line, buffer, i);
	line[i] = '\0';
	ft_memcpy(buffer, buffer + i, BUFFER_SIZE - i);
	buffer[BUFFER_SIZE - i] = '\0';
	return (line);
}

static void	_post_process_buffer_then_append(char **line_ptr, char *buffer)
{
	char	*nl_ptr;
	char	tmp;
	size_t	has_nl;

	has_nl = 0;
	nl_ptr = ft_strchr(buffer, '\n');
	if (nl_ptr != NULL)
	{
		has_nl = 1;
		tmp = nl_ptr[1];
		nl_ptr[1] = '\0';
	}
	else
		nl_ptr = buffer + ft_strlen(buffer);
	ft_strcat(line_ptr, buffer);
	if (*line_ptr == NULL)
		return ;
	if (has_nl)
	{
		nl_ptr[1] = tmp;
		++nl_ptr;
	}
	has_nl = ft_strlen(nl_ptr);
	ft_memcpy(buffer, nl_ptr, has_nl);
	buffer[has_nl] = '\0';
}

static char	*_get_next_line(int fd, char *buffer)
{
	char	*line;
	ssize_t	n;

	line = _preprocess_buffer(buffer);
	if (line == NULL)
		return (NULL);
	while (!ft_strchr(line, '\n'))
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n < 0)
			return (free(line), NULL);
		buffer[n] = '\0';
		if (n == 0 || ft_strchr(buffer, '\n'))
			return (_post_process_buffer_then_append(&line, buffer), line);
		ft_strcat(&line, buffer);
		if (line == NULL)
			return (NULL);
	}
	return (line);
}
