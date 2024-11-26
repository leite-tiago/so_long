/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:12:48 by tborges-          #+#    #+#             */
/*   Updated: 2024/11/26 19:38:10 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"
// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// /**
//  * Verifies if a char is a valid map element.
//  */
// bool	is_valid_char(char c)
// {
// 	return (c == EMPTY_SPACE || c == WALL || c == COLLECTIBLE || c == MAP_EXIT
// 		|| c == PLAYER_STARTING_POSITION);
// }

// /**
//  * Verifies if the map is a rectangle, this means that
//  * every row should have the same amount of collumns
//  * and number of collums must me bigger than the number of
//  * rows.
//  */
// bool	is_rectangle(t_map *map)
// {
// 	int	row;
// 	int	current_col;
// 	int	col;

// 	row = 0;
// 	while (map->data[row] != NULL)
// 	{
// 		current_col = 0;
// 		while (map->data[row][current_col] != '\0')
// 		{
// 			current_col++;
// 		}
// 		if (row == 0)
// 			col = current_col;
// 		if (current_col != col)
// 			return (false);
// 		col = current_col;
// 	}
// 	if (col <= row)
// 		return (false);
// 	return (true);

// }

// /**
//  * Reads the map from the file.
//  */
// t_map	read_map(const char *file)
// {
// 	int		fd;
// 	char	*current_line;
// 	t_map	map;
// 	int		row;
// 	int		col;

// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 		end_program();
// 	current_line = get_next_line(fd);
// 	row = 0;
// 	while (current_line != NULL)
// 	{
// 		col = 0;
// 		while (current_line[col] != '\0')
// 		{
// 			map.data[row][col] = current_line[col];
// 			col++;
// 		}
// 		map.data[row][col] = '\0';
// 		current_line = get_next_line(fd);
// 		row++;
// 	}
// 	map.rows = 0;
// 	while (current_line != NULL)
// 	{
// 		map.cols = 0;
// 		while (current_line[map.cols] != '\0')
// 			map.cols++;
// 		current_line = get_next_line(fd);
// 		map.rows++;
// 	}
// 	free(current_line);
// 	close(fd);
// 	return (map);
// }

// /**
//  * Checks if the map is surrounded by walls.
//  */
// bool	is_surrounde_by_walls(t_map *map)
// {
// 	int	i;

// 	i = 0;
// 	while (i < map->cols)
// 	{
// 		if (map->data[0][i] != '1' || map->data[map->rows - 1][i] != '1')
// 			return (false);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < map->rows)
// 	{
// 		if (map->data[i][0] != '1' || map->data[i][map->cols - 1] != '1')
// 			return (false);
// 		i++;
// 	}
// 	return (true);
// }

// /**
//  * Validates whether the map meets all necessary conditions.
//  */
// void	validate_map(t_map *map)
// {
// 	if (map->count_p != 1 || map->count_e != 1 || map->count_c < 1)
// 	{
// 		write(2, "Error: Invalid map (missing P, E, or C)\n", 41);
// 		exit(1);
// 	}
// 	if (!is_rectangle(map))
// 	{
// 		write(2, "Error: Map is not rectangular\n", 34);
// 		exit(1);
// 	}
// 	if (!is_rectangle(map))
// 	{
// 		write(2, "Error: Map is not surrounded by walls\n", 37);
// 		exit(1);
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	t_map	map;

// 	if (argc != 2)
// 	{
// 		fprintf(stderr, "Usage: %s <map_file.ber>\n", argv[0]);
// 		return (1);
// 	}
// 	// Lê o mapa
// 	map = read_map(argv[1]);
// 	// Valida o mapa
// 	validate_map(&map);
// 	printf("Map is valid!\n");
// 	// Libera a memória do mapa
// 	free_map(&map);
// 	return (0);
// }

// #include "so_long.h" // Inclui ft_printf
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VALID_CHARS "01CEP"

// Estrutura para armazenar o mapa
typedef struct s_map
{
	char **data; // Dados do mapa
	int rows;    // Número de linhas
	int cols;    // Número de colunas
	int count_p; // Contador de 'P'
	int count_e; // Contador de 'E'
	int count_c; // Contador de 'C'
}		t_map;

// Libera memória do mapa
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

// Exibe mensagem de erro e encerra o programa
void	error_exit(const char *message, t_map *map)
{
	if (map)
		free_map(map);
	printf("Error\n%s\n", message);
	exit(1);
}

// Valida se um caractere é permitido
int	is_valid_char(char c)
{
	return (strchr(VALID_CHARS, c) != NULL);
}

// Verifica se o mapa é retangular e contém apenas caracteres válidos
void	validate_map_format(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		if ((int)strlen(map->data[i]) != map->cols)
			error_exit("Map is not rectangular", map);
		j = 0;
		while (j < map->cols)
		{
			if (!is_valid_char(map->data[i][j]))
				error_exit("Map contains invalid characters", map);
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
		error_exit("Map must have 1 P, 1 E, and at least 1 C", map);
}

// Verifica se o mapa está cercado por paredes
void	validate_borders(t_map *map)
{
	int	i;

	i = 0;
	// Verifica bordas horizontais
	while (i < map->cols)
	{
		if (map->data[0][i] != '1' || map->data[map->rows - 1][i] != '1')
			error_exit("Map is not surrounded by walls", map);
		i++;
	}
	// Verifica bordas verticais
	i = 0;
	while (i < map->rows)
	{
		if (map->data[i][0] != '1' || map->data[i][map->cols - 1] != '1')
			error_exit("Map is not surrounded by walls", map);
		i++;
	}
}

// Realiza busca para verificar acessibilidade
void	flood_fill(char **map, int x, int y, int *collectibles, int *exit_found)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	if (map[y][x] == 'C')
		(*collectibles)--;
	if (map[y][x] == 'E')
		(*exit_found) = 1;
	map[y][x] = 'X';
	flood_fill(map, x + 1, y, collectibles, exit_found);
	flood_fill(map, x - 1, y, collectibles, exit_found);
	flood_fill(map, x, y + 1, collectibles, exit_found);
	flood_fill(map, x, y - 1, collectibles, exit_found);
}

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

void	find_player_and_fill(char **copy, t_map *map, int *c, int *e)
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
				flood_fill(copy, x, y, c, e);
				return ;
			}
			x++;
		}
		y++;
	}
}

void	validate_path(t_map *map)
{
	char	**copy;
	int		collectibles;
	int		exit_found;

	copy = malloc(sizeof(char *) * map->rows);
	if (!copy)
		error_exit("Memory allocation failed", map);
	copy_map(copy, map);
	collectibles = map->count_c;
	exit_found = 0;
	find_player_and_fill(copy, map, &collectibles, &exit_found);
	free_copy(copy, map->rows);
	if (collectibles > 0 || exit_found == 0)
		error_exit("Invalid path in map", map);
}

// Função principal para validar o mapa
void	validate_map(t_map *map)
{
	validate_map_format(map);
	validate_borders(map);
	validate_path(map);
}

// Exemplo de leitura e validação do mapa
int	main(void)
{
	t_map	map;
	char	*temp_map[] = {"1111111111111", "10010000000C1", "1000011111001",
			"1P0011E000001", "1111111111111", NULL};
	int		i;

	map.rows = 5;
	map.cols = 13;
	map.count_p = 0;
	map.count_e = 0;
	map.count_c = 0;
	// Alocar dinamicamente cada linha do mapa
	map.data = malloc(sizeof(char *) * map.rows);
	i = 0;
	while (i < map.rows)
	{
		map.data[i] = strdup(temp_map[i]); // Substitui strdup pelo ft_strdup
		i++;
	}
	// Valida o mapa
	validate_map(&map);
	printf("Map is valid!\n");
	// Libera a memória do mapa
	free_map(&map);
	return (0);
}
