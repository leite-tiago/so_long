/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:48:16 by tborges-          #+#    #+#             */
/*   Updated: 2024/11/26 16:49:13 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Frees the memory used by the map.
 */
void	free_map(t_map *map)
{
	for (int i = 0; i < map->rows; i++)
		free(map->data[i]);
	free(map->data);
}
