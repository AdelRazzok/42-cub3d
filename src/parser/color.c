/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:07:26 by arazzok           #+#    #+#             */
/*   Updated: 2024/04/09 19:01:55 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdbool.h>

bool	is_format_correct(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (false);
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ',')
			return (false);
		i++;
	}
	return (true);
}
