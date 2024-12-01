/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 22:45:19 by tborges-          #+#    #+#             */
/*   Updated: 2024/12/01 22:47:46 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_map map, char *direction)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map.rows)
	{
		while (x < map.cols)
		{
			if (map.data[y][x] == 'P')
			{
				if (ft_strncmp(direction, "left", 4) == 0)
				{
					if (map.data[y][x - 1] == 'E')
						exit(0);
					else if (map.data[y][x - 1] == 'C')
						map.count_c--;
					map.data[y][x - 1] = 'P';
					map.data[y][x] = '0';
				}
				else if (ft_strncmp(direction, "up", 2) == 0)
				{
					if (map.data[y - 1][x] == 'E')
						exit(0);
					else if (map.data[y - 1][x] == 'C')
						map.count_c--;
					map.data[y - 1][x] = 'P';
					map.data[y][x] = '0';
				}
				else if (ft_strncmp(direction, "rigth", 5) == 0)
				{
					if (map.data[y][x + 1] == 'E')
						exit(0);
					else if (map.data[y][x + 1] == 'C')
						map.count_c--;
					map.data[y][x + 1] = 'P';
					map.data[y][x] = '0';
				}
				else if (ft_strncmp(direction, "down", 4) == 0)
				{
					if (map.data[y + 1][x] == 'E')
						exit(0);
					else if (map.data[y + 1][x] == 'C')
						map.count_c--;
					map.data[y + 1][x] = 'P';
					map.data[y][x] = '0';
				}
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}
