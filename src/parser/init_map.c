/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:40:17 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/26 11:52:25 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int	init_file(int *fd, char *filename)
{
	if (!filename_checker(filename))
		return (0);
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
		return (0);
	return (1);
}

int	init_map(t_data *data, char **argv)
{
	int		fd;
	
	if (!init_file(&fd, argv[1]))
		return (0);
	if (!init_map_textures(data, fd))
	{
		free_all(data);
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
