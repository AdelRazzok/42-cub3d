/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:58:26 by arazzok           #+#    #+#             */
/*   Updated: 2024/03/26 14:29:59 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H

# define ERROR_H
# define NB_ARGS_ERROR "Error\nNumber of arguments is invalid\n"

# include <stdio.h>
# include <stdlib.h>

void	error(int error_code);
void	check_file(char *file);

#endif
