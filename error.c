/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:31:57 by tborges-          #+#    #+#             */
/*   Updated: 2024/11/30 11:47:54 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Exits the program with an error message.
 * Frees the map memory if it exists.
 */
void	error_exit(const char *message, t_map *map)
{
	if (map)
		free_map(map);
	ft_printf("Error\n%s\n", message);
	exit(1);
}
