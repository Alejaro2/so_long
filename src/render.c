/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:11:58 by alejaro2          #+#    #+#             */
/*   Updated: 2025/04/02 11:22:10 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_images(t_game *game)
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

void	render_map(t_game *game)
{
	int	i;
	int	j;
	int first_render;
	
	first_render = 1;
	i = 0;
	
	if(first_render)
	{
		while (i < game->map.height)
		{
			j = 0;
			while (j < game->map.width)
			{
				if (game->map.map[i][j] == '1')
					mlx_image_to_window(game->mlx, game->img_wall, j * 64, i * 64);
				else if (game->map.map[i][j] == '0')
					mlx_image_to_window(game->mlx, game->img_floor, j * 64, i * 64);
				else if (game->map.map[i][j] == 'P')
					mlx_image_to_window(game->mlx, game->img_player, j * 64, i
						* 64);
				else if (game->map.map[i][j] == 'C')
					mlx_image_to_window(game->mlx, game->img_collect, j * 64, i
						* 64);
				else if (game->map.map[i][j] == 'E')
					mlx_image_to_window(game->mlx, game->img_exit, j * 64, i * 64);
				j++;
			}
			i++;
		}
		first_render = 0;
	}
	
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

void	init_game(t_game *game)
{
	game->mlx = mlx_init(game->map.width * 64, game->map.height * 64, "so long",
			false);
	if (!game->mlx)
		ft_error("Error\n Failed to initialize MLX\n");
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	load_images(game);
	find_player(game, &game->player_x, &game->player_y);
	game->moves = 0;
	find_exit(game);
	mlx_key_hook(game->mlx, move_player, game);
}
