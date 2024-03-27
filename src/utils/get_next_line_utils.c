/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:16:02 by arazzok           #+#    #+#             */
/*   Updated: 2024/03/27 14:21:38 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i++ < n)
		*(char *)dst++ = *(char *)src++;
	return ((void *)((char *)dst - i));
}

void	ft_strcat(char **dst_ptr, const char *src)
{
	size_t	dst_size;
	size_t	src_size;
	char	*res;

	dst_size = ft_strlen(*dst_ptr);
	src_size = ft_strlen(src);
	res = (char *)malloc(dst_size + src_size + 1);
	if (res != NULL)
	{
		ft_memcpy(res, *dst_ptr, dst_size);
		ft_memcpy(res + dst_size, src, src_size);
		res[dst_size + src_size] = '\0';
	}
	free(*dst_ptr);
	*dst_ptr = res;
}
