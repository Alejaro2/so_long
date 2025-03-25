/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:10:15 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/25 18:53:38 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void find_player(t_game *game, int *x, int *y)
{
	int i;
	int j;

	i = 0;
	while (i <  game->map.height)
	{
		j = 0;
		while(j < game->map.width)
		{
			if(game->map.map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return;
			}
			j++;
		}
		i++;
	}	
}
static char **copy_map(t_game *game)
{
	char **copy;
	int i;

	copy = malloc(sizeof(char *) * (game->map.height + 1));
	if(!copy)
		ft_error("Error1\n");
	i = 0;
	while (i < game->map.height)
	{
		copy[i] = ft_strdup(game->map.map[i]);
		if(!copy[i])
		{
			while (i-- > 0)
				free(copy[i]);
			free(copy);
			ft_error("Error\n");
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

// void flood_fill(char **map, int x, int y, int width, int height)
// {
// 	if(x < 0 || x >= width || y < 0 || y >= height)
// 		return;
// 	if(map[y][x] == '1' || map [y][x] == 'F')
// 		return;
// 	map[y]
// }