/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:12:48 by tborges-          #+#    #+#             */
/*   Updated: 2024/12/02 16:36:45 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * Main function to validate the map.
 */
void	validate_map(t_map *map)
{
	validate_map_format(map);
	validate_borders(map);
	validate_path(map);
}

/**
 * Verifies if the map is rectangular and contains only valid characters.
 */
void	validate_map_format(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		if ((int)ft_strlen(map->data[i]) != map->cols)
			error_exit_map("Map is not rectangular", map);
		j = 0;
		while (j < map->cols)
		{
			if (!is_valid_char(map->data[i][j]))
				error_exit_map("Map contains invalid characters", map);
			if (map->data[i][j] == 'P')
				map->count_p++;
			if (map->data[i][j] == 'E')
				map->count_e++;
			if (map->data[i][j] == 'C')
				map->count_c++;
			j++;
		}
		i++;
	}
	if (map->count_p != 1 || map->count_e != 1 || map->count_c < 1)
		error_exit_map("Map must have 1 P, 1 E, and at least 1 C", map);
}

/**
 * Verifies if the map is surrounded by walls.
 */
void	validate_borders(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->cols)
	{
		if (map->data[0][i] != '1' || map->data[map->rows - 1][i] != '1')
			error_exit_map("Map is not surrounded by walls", map);
		i++;
	}
	i = 0;
	while (i < map->rows)
	{
		if (map->data[i][0] != '1' || map->data[i][map->cols - 1] != '1')
			error_exit_map("Map is not surrounded by walls", map);
		i++;
	}
}

/**
 * Validates the path in the map.
 */
void	validate_path(t_map *map)
{
	char	**copy;
	t_flood	flood;

	copy = malloc(sizeof(char *) * map->rows);
	if (!copy)
		error_exit_map("Memory allocation failed", map);
	copy_map(copy, map);
	flood.collectibles = map->count_c;
	flood.exit_found = 0;
	find_player_and_fill(copy, map, &flood);
	free_copy(copy, map->rows);
	if (flood.collectibles > 0 || flood.exit_found == 0)
		error_exit_map("Invalid path in map", map);
}
