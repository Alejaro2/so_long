/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:42:40 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/26 15:23:35 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	read_map(t_game *game)
{
	char	*line;

	game->map.height = 0;
	line = get_next_line(game->fd);
	while (line)
	{
		game->map.height++;
		free(line);
		line = get_next_line(game->fd);
	}
	game->map.map = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.map)
		ft_error("Error\n");
	close(game->fd);
}
void	store_lines(t_game *game, char *filename)
{
	char	*line;
	int		i;

	game->fd = open(filename, O_RDONLY);
	if (game->fd == -1)
		ft_error("Error\n");
	i = 0;
	line = get_next_line(game->fd);
	if (!line)
		ft_error("Empty map\n");
	while (line)
	{
		game->map.map[i] = line;
		i++;
		line = get_next_line(game->fd);
	}
	game->map.map[i] = NULL;
}

void	map_parce(t_game *game, char *filename)
{
	check_file(filename);
	read_map(game);
	store_lines(game, filename);
	is_rectangular(game);
	check_walls(game);
	check_components(game);
	
}
