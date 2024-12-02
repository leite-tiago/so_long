/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 22:45:19 by tborges-          #+#    #+#             */
/*   Updated: 2024/12/02 19:45:06 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, t_coordinates current,
		t_coordinates destination)
{
	t_map	*map;

	map = &(game->map);
	if (map->data[destination.y][destination.x] == 'C')
		map->count_c--;
	else if (map->data[destination.y][destination.x] == 'E'
		&& map->count_c == 0)
		exit(0);
	map->data[destination.y][destination.x] = 'P';
	map->data[current.y][current.x] = '0';
	game->count_moves++;
	ft_printf("Moves: %d\n", game->count_moves);
}

void	move_left(t_game *game)
{
	t_coordinates	current;
	t_coordinates	destination;

	current = get_player_position(game->map);
	destination.x = current.x - 1;
	destination.y = current.y;
	check_restritions(game, current, destination);
}

void	move_up(t_game *game)
{
	t_coordinates	current;
	t_coordinates	destination;

	current = get_player_position(game->map);
	destination.x = current.x;
	destination.y = current.y - 1;
	check_restritions(game, current, destination);
}

void	move_rigth(t_game *game)
{
	t_coordinates	current;
	t_coordinates	destination;

	current = get_player_position(game->map);
	destination.x = current.x + 1;
	destination.y = current.y;
	check_restritions(game, current, destination);
}

void	move_down(t_game *game)
{
	t_coordinates	current;
	t_coordinates	destination;

	current = get_player_position(game->map);
	destination.x = current.x;
	destination.y = current.y + 1;
	check_restritions(game, current, destination);
}
