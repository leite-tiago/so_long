/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:48:16 by tborges-          #+#    #+#             */
/*   Updated: 2024/11/30 17:19:32 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Frees the memory used by the map.
 */
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
 * Frees the memory used by the game.
 */
void	free_textures(t_game *game)
{
	t_textures	*textures;

	textures = &game->textures;
	if (textures->wall)
		mlx_destroy_image(game->mlx, textures->wall);
	if (textures->floor)
		mlx_destroy_image(game->mlx, textures->floor);
	if (textures->player)
		mlx_destroy_image(game->mlx, textures->player);
	if (textures->collectible)
		mlx_destroy_image(game->mlx, textures->collectible);
	if (textures->exit)
		mlx_destroy_image(game->mlx, textures->exit);
}

/**
 * Frees the memory used by the game.
 */
void	free_game(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free_textures(game);
	free_map(&game->map);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
