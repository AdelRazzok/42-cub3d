/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:58:26 by arazzok           #+#    #+#             */
/*   Updated: 2024/03/30 13:27:04 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H

# define ERROR_H
# define MSG_NB_ARGS "Error\nWrong number of arguments\n"
# define MSG_EXTENSION "Error\nWrong file extention\n"
# define MSG_FILE "Error\nNo such file or directory\n"
# define MSG_MALLOC "Error\nMap memory allocation failed\n"
# define MSG_DUPLICATE "Error\nDuplicate element\n"
# define MSG_MISSSING_ELEMENT "Error\nMissing element\n"

# include "parser.h"

typedef enum e_error
{
	ERR_NB_ARGS,
	ERR_EXTENSION,
	ERR_FILE,
	ERR_MALLOC,
	ERR_DUPLICATE,
	ERR_MISSSING_ELEMENT
}		t_error;

void	error(t_error error_code);
void	check_file(const char *path, const char *extension);
void	free_and_error(t_error error_code, t_map *fmap);

#endif
