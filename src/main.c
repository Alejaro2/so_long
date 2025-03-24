/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:55:22 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/24 11:41:18 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
	{
		ft_printf("Usage: ./so_long <map2.ber>\n");
		return(1);
	}
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd == -1)
		ft_error("Erro\n");
	read_map(&game);
	store_lines(&game, argv[1]);
	close(game.fd);
	
	return(0);
}
