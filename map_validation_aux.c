/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_aux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:25:39 by tborges-          #+#    #+#             */
/*   Updated: 2024/11/28 12:39:53 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Finds the player position and starts the flood fill algorithm.
 */
void	find_player_and_fill(char **copy, t_map *map, t_flood *flood)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (copy[y][x] == 'P')
			{
				flood_fill(copy, x, y, flood);
				return ;
			}
			x++;
		}
		y++;
	}
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

/**
 * Copies the map to be used in the flood fill algorithm.
 */
void	copy_map(char **copy, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		copy[i] = strdup(map->data[i]);
		if (!copy[i])
			error_exit("Memory allocation failed", map);
		i++;
	}
}

/**
 * Flood fill algorithm to check if the map is solvable.
 */
void	flood_fill(char **map, int x, int y, t_flood *flood)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	if (map[y][x] == 'C')
		flood->collectibles--;
	if (map[y][x] == 'E')
		flood->exit_found = 1;
	map[y][x] = 'X';
	flood_fill(map, x + 1, y, flood);
	flood_fill(map, x - 1, y, flood);
	flood_fill(map, x, y + 1, flood);
	flood_fill(map, x, y - 1, flood);
}

/**
 * Verifies if a char is a valid map element.
 */
int	is_valid_char(char c)
{
	return (ft_strchr(VALID_CHARS, c) != NULL);
}
