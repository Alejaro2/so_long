/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:36:04 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/24 11:40:25 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "ft_printf/include/ft_printf.h"
# include "include/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_map {
	int width;
	int height;
	char **map;
}t_map;

typedef struct s_game {
	t_map map;
	int fd;
}t_game;

void read_map(t_game *game);
void ft_error (char *str);
void store_lines(t_game *game, char *filename);

#endif

