/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:47:14 by arazzok           #+#    #+#             */
/*   Updated: 2024/04/14 13:29:03 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# define FD_LIMIT 1024

# include "parser.h"
# include "scene.h"

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
char		*ft_strdup(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		skip_spaces(char **str);
char		**arrdup(char **src, int size);
int			ft_atoi(const char *str);

/* ************************************************************************** */
/*                                                                            */
/* get_next_line                                                              */
/*                                                                            */
/* ************************************************************************** */

void		*ft_memcpy(void *dst, const void *src, size_t n);
void		ft_strcat(char **dst_ptr, const char *src);
char		*get_next_line(int fd);

/* ************************************************************************** */
/*                                                                            */
/* t_map_utils                                                               */
/*                                                                            */
/* ************************************************************************** */

t_map		*init_map(void);
void		free_map(t_map *fmap);
void		free_array(char **array);

/* ************************************************************************** */
/*                                                                            */
/* t_mlx utils                                                                */
/*                                                                            */
/* ************************************************************************** */

t_mlx		*init_mlx(t_map *fmap);
void		free_mlx(t_mlx *mlx);

/* ************************************************************************** */
/*                                                                            */
/* t_texture_utils                                                            */
/*                                                                            */
/* ************************************************************************** */

t_texture	*init_texture(t_map *fmap, t_mlx *mlx);
void		free_texture(t_texture *texture);

#endif
