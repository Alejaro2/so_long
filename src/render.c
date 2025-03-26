/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:11:58 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/26 18:04:06 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_game(t_game *game)
{
	game->mlx = mlx_init(game->map.width * 64, game->map.height * 64, "so long", false);
	if(!game->mlx)
		ft_error("Error\n Failed to initialize MLX\n");
	mlx_loop(game->mlx);
}