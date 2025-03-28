/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:55:22 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/28 11:51:57 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game game;
	int j;

	j = 0;
	if (argc != 2)
	{
		ft_printf("Usage: ./so_long <map2.ber>\n");
		return(1);
	}
	game.map.height = 0;
	game.map.map = NULL;
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd == -1)
		ft_error("Error\n");
	map_parce(&game, argv[1]);
	// while (game.map.map[j])
	// 	printf("%s", game.map.map[j++]);
	init_game(&game);
	path_finder(&game);
	render_map(&game);
	mlx_loop(game.mlx);
	free_map(&game);
	close(game.fd);
	return(0);
}
