/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:55:22 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/21 17:35:33 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	// char *line;
	t_map *game;

	game = NULL;

	if (argc != 2)
	{
		ft_printf("Usage: ./so_long <map2.ber>\n");
		return(1);
	}
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd == -1)
	{
		perror("Error");
		return (1);
	}
	
	return(0);
}
