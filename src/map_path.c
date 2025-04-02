/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:10:15 by alejaro2          #+#    #+#             */
/*   Updated: 2025/04/02 10:55:38 by alejaro2         ###   ########.fr       */
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

void flood_fill(t_game *game, char **map, int x, int y)
{
    if (x < 0 || x >= game->map.width || y < 0 || y >= game->map.height)
        return;
    if (map[y][x] == '1' || map[y][x] == 'F')
        return;
    if (map[y][x] == 'C')
        game->collectibles--;
    if (map[y][x] == 'E')
        game->exits_total--;
    map[y][x] = 'F';
    flood_fill(game, map, x + 1, y);
    flood_fill(game, map, x - 1, y);
    flood_fill(game, map, x, y + 1);
    flood_fill(game, map, x, y - 1);
}

// int check_path(char **map, int height)
// {
// 	int i;
// 	int j;
	
// 	i = 0;
// 	while (i < height)
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if(map[i][j] == 'C' || map[i][j] == 'E')
// 				return(1);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return(0);
// }

// void path_finder(t_game *game)
// {
//     char **map_copy;
//     int x;
//     int y;
//     int initial_c = game->collectibles;
//     int initial_e = game->exits_total;

//     find_player(game, &x, &y);
//     map_copy = copy_map(game);
//     flood_fill(game, map_copy, x, y);
//     if (game->collectibles != 0 || game->exits_total != 0)
//     {
//         free_map(game);
//         free_map_copy(map_copy, game->map.height);
//         ft_error("Error: No valid path to C or E\n");
//     }
//     game->collectibles = initial_c;
//     game->exits_total = initial_e;
//     free_map_copy(map_copy, game->map.height);
// }

void path_finder(t_game *game)
{
    char **map_copy;
    int x;
    int y;
    int initial_c = game->collectibles;
    int initial_e = game->exits_total;

    ft_printf("Initial C: %d, E: %d\n", initial_c, initial_e);
    find_player(game, &x, &y);
    map_copy = copy_map(game);
    flood_fill(game, map_copy, x, y);
    ft_printf("After flood_fill C: %d, E: %d\n", game->collectibles, game->exits_total);
    if (game->collectibles != 0 || game->exits_total != 0)
    {
        free_map(game);
        free_map_copy(map_copy, game->map.height);
        ft_error("Error: No valid path to C or E\n");
    }
    game->collectibles = initial_c;
    game->exits_total = initial_e;
    free_map_copy(map_copy, game->map.height);
}

