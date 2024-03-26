/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:58:26 by arazzok           #+#    #+#             */
/*   Updated: 2024/03/26 18:37:15 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H

# define ERROR_H
# define MSG_NB_ARGS "Error\nWrong number of arguments\n"
# define MSG_EXTENSION "Error\nWrong file extention\n"
# define MSG_FILE "Error\nNo such file or directory\n"

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_error
{
	ERR_NB_ARGS,
	ERR_EXTENSION,
	ERR_FILE
}		t_error;

void	error(t_error error_code);
void	check_file(const char *path, const char *extension);

#endif
