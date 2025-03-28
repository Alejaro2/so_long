/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:35:23 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/28 11:30:01 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
}

void free_map_copy(char **map, int height)
{
    int i;

    i = 0;
    while (i < height)
        free(map[i++]);
    free(map);
}

int check_counts(t_counts counts)
{
    if (counts.p != 1 || counts.e != 1 || counts.c < 1)
        return(1);
	else
		return(0);
}
void cleanup_game(t_game *game)
{
    free_map(game);
    mlx_terminate(game->mlx);
    exit(0);
}