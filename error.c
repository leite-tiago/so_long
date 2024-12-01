/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:31:57 by tborges-          #+#    #+#             */
/*   Updated: 2024/12/01 20:33:05 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Exits the program with an error message.
 */
void	error_exit(const char *message)
{
	ft_printf("Error\n%s\n", message);
	exit(1);
}

/**
 * Exits the program with an error message.
 * Frees the map memory if it exists.
 */
void	error_exit_map(const char *message, t_map *map)
{
	if (map)
		free_map(map);
	error_exit(message);
}

/**
 * Exits the program with an error message.
 * Frees the game memory if it exists.
 */
void	error_exit_game(const char *message, t_game *game)
{
	//
	ft_printf("houve erro");
	//
	if (game)
		free_game(game);
	error_exit(message);
}
