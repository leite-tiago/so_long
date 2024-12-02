/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:44:04 by tborges-          #+#    #+#             */
/*   Updated: 2024/12/02 19:45:03 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_restritions(t_game *game, t_coordinates current,
		t_coordinates destination)
{
	t_map	*map;

	map = &(game->map);
	if (map->data[destination.y][destination.x] == '1')
		return ;
	else if (map->data[destination.y][destination.x] == 'E'
		&& map->count_c != 0)
		return ;
	else
		move_player(game, current, destination);
}

t_coordinates	get_player_position(t_map map)
{
	t_coordinates	position;
	int				x;
	int				y;

	y = 0;
	while (y < map.rows)
	{
		x = 0;
		while (x < map.cols)
		{
			if (map.data[y][x] == 'P')
			{
				position.x = x;
				position.y = y;
				return (position);
			}
			x++;
		}
		y++;
	}
	position.x = -1;
	position.y = -1;
	return (position);
}
