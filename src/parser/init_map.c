/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:40:17 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/25 20:32:10 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	init_map(t_data *data, char **argv)
{	
	int		fd;

	if (!filename_checker(argv[1]))
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	if (!init_map_textures(data, fd))
	{
		close(fd);
		return (0);
	}
	data->map = ft_calloc_c(1, sizeof(t_map));
	if (!init_map_data(data->map, fd) || !data->map)
	{
		free_all(data);
		close(fd);
		return (0);
	}
	close(fd);
	if (!map_validator(data))
	{
		free_all(data);
		return (0);
	}
	return (1);
}
