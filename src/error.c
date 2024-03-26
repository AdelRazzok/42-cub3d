/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:50:15 by arazzok           #+#    #+#             */
/*   Updated: 2024/03/26 14:33:41 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * * FAIT 1. Mauvais nombre d'arguments
 * TODO: 2. Mauvais format d'arguments
 * TODO: 3. Fichier inexistant
 * TODO: 4. Absence d'un d'un element
 * TODO: 5. Map invalide
 */

#include "error.h"

void	error(int error_code)
{
	if (error_code == 1)
		printf(NB_ARGS_ERROR);
	exit(1);
}

void	check_file(char *file)
{
    
}
