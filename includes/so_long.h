/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:36:04 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/21 17:35:00 by alejaro2         ###   ########.fr       */
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
	char **map;
	int width;
	int height;
	int fd;
}t_map;

void init_map(t_map *game);
#endif

