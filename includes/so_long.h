/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:36:04 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/25 16:26:42 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/include/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "include/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
}			t_map;

typedef struct s_game
{
	t_map	map;
	int		fd;
}			t_game;

typedef struct s_counts
{
	int p; // Jugador
	int e; // Salida
	int c; // Coleccionables
}			t_counts;

void		ft_error(char *str);
void		read_map(t_game *game);
void		store_lines(t_game *game, char *filename);
void		free_map(t_game *game);
void		check_file(char *filename);
void		is_rectangular(t_game *game);
void		check_walls(t_game *game);
void		check_components(t_game *game);
void		count_elements(t_game *game, t_counts *counts);
void		check_counts(t_counts counts);
void		map_parce(t_game *game, char *filename);
static void	find_player(t_game *game, int *x, int *y)

#endif
