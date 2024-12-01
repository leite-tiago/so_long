/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:55:05 by tborges-          #+#    #+#             */
/*   Updated: 2024/12/01 20:23:50 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * Reads the map file line by line and stores it in the map structure.
 */
void	read_map_from_file(const char *filename, t_map *map)
{
	int	fd;
	int	i;

	fd = open_map_file(filename);
	map->rows = count_lines_in_file(fd);
	allocate_map_data(map);
	fd = open_map_file(filename);
	i = 0;
	while (i < map->rows)
	{
		read_map_line(fd, map, i);
		i++;
	}
	close(fd);
}

/**
 * Reads a line from the map file and stores it in the map structure.
 */
void	read_map_line(int fd, t_map *map, int index)
{
	map->data[index] = get_next_line(fd);
	if (!map->data[index])
		error_exit("Failed to read line from file");
	if (map->cols == 0)
		map->cols = ft_strlen(map->data[index]);
	else if ((int)ft_strlen(map->data[index]) != map->cols)
		error_exit_map("Map is not rectangular", map);
}
