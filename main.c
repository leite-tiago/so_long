/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourusername <youremail@student.42.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: YYYY/MM/DD HH:MM:SS by yourusername     #+#    #+#             */
/*   Updated: YYYY/MM/DD HH:MM:SS by yourusername    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_map {
	char	**data;
	int		rows;
	int		cols;
	int		count_p;
	int		count_e;
	int		count_c;
}	t_map;

void	init_map(int argc, char **argv, t_map *map);

int	main(int argc, char **argv)
{
	t_map	map;

	init_map(argc, argv, &map);
	printf("Map initialized successfully!\n");
	validate_map(&map);
	return (0);
}
