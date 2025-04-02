/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 02:11:04 by alejaro2          #+#    #+#             */
/*   Updated: 2025/04/02 13:05:00 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_map(t_game *game, int new_x, int new_y)
{
	t_pos	old_pos;
	t_pos	new_pos;

	old_pos.x = game->player_x;
	old_pos.y = game->player_y;
	new_pos.x = new_x;
	new_pos.y = new_y;
	if (old_pos.x == game->exit_x && old_pos.y == game->exit_y)
		game->map.map[old_pos.y][old_pos.x] = 'E';
	else
		game->map.map[old_pos.y][old_pos.x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	update_player_position(game, old_pos, new_pos);
}

void	execute_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map.width || new_y < 0
		|| new_y >= game->map.height)
		return ;
	if (game->map.map[new_y][new_x] == '1')
		return ;
	if (game->map.map[new_y][new_x] == 'C')
		game->collectibles--;
	if (new_x == game->exit_x && new_y == game->exit_y && !game->collectibles)
		check_victory(game);
	update_map(game, new_x, new_y);
}

void	move_player(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		new_x;
	int		new_y;

	game = (t_game *)param;
	new_x = game->player_x;
	new_y = game->player_y;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		cleanup_game(game);
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		new_y--;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		new_y++;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		new_x--;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		new_x++;
	else
		return ;
	execute_move(game, new_x, new_y);
}

void	update_player_position(t_game *game, t_pos old_pos, t_pos new_pos)
{
	if (old_pos.x == game->exit_x && old_pos.y == game->exit_y)
		mlx_image_to_window(game->mlx, game->img_exit, old_pos.x * 64, old_pos.y
			* 64);
	else
		mlx_image_to_window(game->mlx, game->img_floor, old_pos.x * 64,
			old_pos.y * 64);
	mlx_image_to_window(game->mlx, game->img_player, new_pos.x * 64, new_pos.y
		* 64);
}

void	check_victory(t_game *game)
{
	ft_printf("You win! Moves: %d\n", game->moves);
	cleanup_game(game);
	mlx_terminate(game->mlx);
	exit(0);
}
