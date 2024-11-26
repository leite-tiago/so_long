/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:02:14 by tborges-          #+#    #+#             */
/*   Updated: 2024/11/26 16:50:58 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <mlx.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_map
{
	char **data; // Armazena o mapa
	int rows;    // Número de linhas
	int cols;    // Número de colunas
	int count_p; // Contador de 'P'
	int count_e; // Contador de 'E'
	int count_c; // Contador de 'C'
}		t_map;

// events
enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

// map components
#define EMPTY_SPACE '0'
#define WALL '1'
#define COLLECTIBLE 'C'
#define MAP_EXIT 'E'
#define PLAYER_STARTING_POSITION 'P'


// error
void	end_program(void);

// frees
void	free_map(t_map *map);
