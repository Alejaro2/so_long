/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:42:40 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/21 17:34:22 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_map(t_map *game)
{
	game->height = 0;
	game->width = 0;
	game->map = read_map(game); 
}
void ft_error (char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

char **read_map(t_map *game)
{
	char *line;
	char **result;
	
	line = get_next_line(game->fd);
	game->width = ft_strlen(line);
	while (line)
	{
		game->height++;
		free(line);
		line = get_next_line(game->fd);
		if(game->width != ft_strlen(line))
			return(free(line), ft_error("Invalid map\n"), NULL);
	}
	result = malloc(sizeof(char *) * (game->height + 1));
	if(!result)
		ft_error("Error\n");
	close(game->fd);
	line = get_next_line(game->fd);
	// result = info_map(game);
		
} 
