/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:11:58 by alejaro2          #+#    #+#             */
/*   Updated: 2025/04/02 14:52:14 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("assets/textures/wall.png");
	game->img_wall = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("assets/textures/floor.png");
	game->img_floor = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("assets/textures/player.png");
	game->img_player = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("assets/textures/collect.png");
	game->img_collect = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("assets/textures/exit.png");
	game->img_exit = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_collect || !game->img_exit)
		ft_error("Error\n Failed to load images\n");
}

void	put_image(t_game *game, char cell, int x, int y)
{
	if (cell == '1')
		mlx_image_to_window(game->mlx, game->img_wall, x, y);
	else if (cell == '0')
		mlx_image_to_window(game->mlx, game->img_floor, x, y);
	else if (cell == 'P')
		mlx_image_to_window(game->mlx, game->img_player, x, y);
	else if (cell == 'C')
		mlx_image_to_window(game->mlx, game->img_collect, x, y);
	else if (cell == 'E')
		mlx_image_to_window(game->mlx, game->img_exit, x, y);
}

void	render_map(t_game *game)
{
	int			i;
	int			j;
	static int	first_render;

	first_render = 1;
	if (!first_render)
		return ;
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			put_image(game, game->map.map[i][j], j * 64, i * 64);
			j++;
		}
		i++;
	}
	first_render = 0;
}

int	count_collectibles(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	count_exits(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
