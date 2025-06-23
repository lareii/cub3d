/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:40:17 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/23 12:56:20 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stddef.h>

int	init_map(t_map *map, char *line)
{
	(void)map;
	(void)line;
	return (1);
}

int	init_map_data(t_data *data, char **argv)
{
	int	fd;

	if (!filename_checker(argv[1]))
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	if (!init_map_textures(data, fd))
		return (0);
	return (1);
}
