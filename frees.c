/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:48:16 by tborges-          #+#    #+#             */
/*   Updated: 2024/11/30 12:16:30 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Frees the memory used by the map.
 */
void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		free(map->data[i]);
		i++;
	}
	free(map->data);
}

/**
 * Frees the copy map.
 */
void	free_copy(char **copy, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(copy[i]);
		i++;
	}
	free(copy);
}
