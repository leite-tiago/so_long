/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:57:09 by tborges-          #+#    #+#             */
/*   Updated: 2024/11/30 12:18:38 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * Initializes the map structure.
 */
void	init_map(int argc, char **argv, t_map *map)
{
	if (argc != 2)
	{
		ft_printf("Error\nUsage: %s <map_file.ber>\n", argv[0]);
		exit(1);
	}
	check_file_extension(argv[1]);
	ft_memset(map, 0, sizeof(t_map));
	read_map_from_file(argv[1], map);
	validate_map(map);
}

/**
 * Checks if the file extension is .ber.
 */
void	check_file_extension(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
	{
		ft_printf("Error\nInvalid file extension. Must be .ber\n");
		exit(1);
	}
}

/**
 * Counts the number of lines in the file.
 */
int	count_lines_in_file(int fd)
{
	int		lines;
	char	*line;

	lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	if (lines == 0)
	{
		ft_printf("Error\nEmpty map file\n");
		exit(1);
	}
	close(fd);
	return (lines);
}

/**
 * Opens the map file.
 */
int	open_map_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFailed to open file\n");
		exit(1);
	}
	return (fd);
}

/**
 * Allocates memory for the map data.
 */
void	allocate_map_data(t_map *map)
{
	map->data = malloc(sizeof(char *) * map->rows);
	if (!map->data)
	{
		ft_printf("Error\nMemory allocation failed\n");
		exit(1);
	}
}
