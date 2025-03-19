/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:55:22 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/19 17:08:22 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		int fd;
		fd = open(argv[1], O_RDONLY);
		if(fd = -1)
		{
			perror("No such file or directory");
			return(1);
		}
		close(fd);
	}
	else
	{
		  			
	}
	return(0);
}
