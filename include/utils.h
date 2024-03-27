/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:47:14 by arazzok           #+#    #+#             */
/*   Updated: 2024/03/27 14:20:30 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# define FD_LIMIT 1024

typedef struct s_gnl
{
	char	*line;
	char	*newline;
	int		count;
	int		to_copy;
}			t_gnl;

/* ************************************************************************** */
/*                                                                            */
/* str_utils                                                                  */
/*                                                                            */
/* ************************************************************************** */

size_t		ft_strlen(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *str, char c);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);

/* ************************************************************************** */
/*                                                                            */
/* get_next_line                                                              */
/*                                                                            */
/* ************************************************************************** */

void		*ft_memcpy(void *dst, const void *src, size_t n);
void		ft_strcat(char **dst_ptr, const char *src);
char		*get_next_line(int fd);

#endif
