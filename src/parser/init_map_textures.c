/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 20:15:22 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/24 12:25:30 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <stddef.h>

static int	set_textures(t_data *data)
{
	data->textures = malloc(sizeof(t_textures));
	if (!data->textures)
		return (0);
	data->textures->north = NULL;
	data->textures->south = NULL;
	data->textures->west = NULL;
	data->textures->east = NULL;
	data->textures->floor = -1;
	data->textures->ceiling = -1;
	return (1);
}

static int	set_texture_path(void **data, char *line)
{
	char	*path;

	if (!*data)
	{
		path = ft_strtrim(line + 3, " \n"); // trim whitespaces or lf
		if (!path)
			return (0);
		*data = path; // we cant set images from here, there is no mlx_ptr initalized
		return (1);
	}
	return (0);
}

static int	all_textures_set(t_textures *textures)
{
	if (textures->north && textures->south && textures->west
		&& textures->east && textures->floor != -1 && textures->ceiling != -1)
		return (1);
	return (0);
}

static int	parse_textures(t_data *data, char *line)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		return (set_texture_path(&data->textures->north, line));
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		return (set_texture_path(&data->textures->south, line));
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		return (set_texture_path(&data->textures->west, line));
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		return (set_texture_path(&data->textures->east, line));
	else if (line[0] == 'F' && line[1] == ' ')
	{
		data->textures->floor = str_to_rgb(line + 2);
		return (data->textures->floor != -1);
	}
	else if (line[0] == 'C' && line[1] == ' ')
	{
		data->textures->ceiling = str_to_rgb(line + 2);
		return (data->textures->ceiling != -1);
	}
	return (0);
}

int	init_map_textures(t_data *data, int fd)
{
	char	*line;

	if (!set_textures(data))
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] != '\n' && !parse_textures(data, line))
		{
			free(line);
			break ;
		}
		free(line);
		if (all_textures_set(data->textures))
			break ;
	}
	get_next_line(-1); // gnl leaks for static value here, so we pass -1 for free buffer
	if (!all_textures_set(data->textures)) // check for missing value
	{
		free_textures(data->textures);
		return (0);
	}
	return (1);
}
