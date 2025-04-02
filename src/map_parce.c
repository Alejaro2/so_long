/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:42:40 by alejaro2          #+#    #+#             */
/*   Updated: 2025/04/02 18:27:20 by alejaro2         ###   ########.fr       */
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
		ft_error("Error: Memory allocation failed.\n");
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

void	check_png_files(void)
{
	int	fd;

	fd = open("assets/textures/wall.png", O_RDONLY);
	if (fd == -1)
		ft_error("Error: wall.png missing or not readable\n");
	close(fd);
	fd = open("assets/textures/floor.png", O_RDONLY);
	if (fd == -1)
		ft_error("Error: floor.png missing or not readable\n");
	close(fd);
	fd = open("assets/textures/player.png", O_RDONLY);
	if (fd == -1)
		ft_error("Error: player.png missing or not readable\n");
	close(fd);
	fd = open("assets/textures/collect.png", O_RDONLY);
	if (fd == -1)
		ft_error("Error: collect.png missing or not readable\n");
	close(fd);
	fd = open("assets/textures/exit.png", O_RDONLY);
	if (fd == -1)
		ft_error("Error: exit.png missing or not readable\n");
	close(fd);
}

void	restrict_map_to_screen(t_game *game)
{
	int	map_width_pixels;
	int	map_height_pixels;

	map_width_pixels = game->map.width * TILE_SIZE;
	map_height_pixels = game->map.height * TILE_SIZE;
	if (map_width_pixels > SCREEN_WIDTH_LIMIT
		|| map_height_pixels > SCREEN_HEIGHT_LIMIT)
	{
		ft_printf("Error\nMap too large: %dx%d exceeds screen size %dx%d\n",
			map_width_pixels, map_height_pixels, SCREEN_WIDTH_LIMIT,
			SCREEN_HEIGHT_LIMIT);
		free_map(game);
		ft_error("Error\n");
	}
}
