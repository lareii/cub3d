/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 20:15:22 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/23 00:41:15 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <stddef.h>

static void	set_textures(t_textures *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->west = NULL;
	textures->east = NULL;
	textures->floor = -1;
	textures->ceiling = -1;
}

static int	init_textures(t_mlx *mlx, void *data, char *line)
{
	// probably not working the way i want to do
	if (data == NULL)
	{
		data = mlx_xpm_file_to_image(mlx->mlx_ptr, line + 3, NULL, NULL);
		if (data == NULL)
		{
			free(line);
			return (0);
		}
		free(line);
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

static int	parse_textures(t_data *data, t_mlx *mlx, char *line)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		return (init_textures(mlx, data->textures->north, line));
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		return (init_textures(mlx, data->textures->south, line));
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		return (init_textures(mlx, data->textures->west, line));
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		return (init_textures(mlx, data->textures->east, line));
	else if (line[0] == 'F' && line[1] == ' ')
	{
		data->textures->floor = str_to_rgb(line + 2);
		free(line);
		return (data->textures->floor != -1);
	}
	else if (line[0] == 'C' && line[1] == ' ')
	{
		data->textures->ceiling = str_to_rgb(line + 2);
		free(line);
		return (data->textures->ceiling != -1);
	}
	free(line);
	return (0);
}

int	init_map_textures(t_data *data, int fd)
{
	char	*line;

	data->textures = malloc(sizeof(t_textures));
	if (!data->textures)
		return (0);
	set_textures(data->textures);
	while (1)
	{
		if (all_textures_set(data->textures))
			return (1);
		line = get_next_line(fd);
		if (!line)
			break;
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		if (!parse_textures(data, data->mlx, line))
		{
			free(data->textures); // fix leak fly pictures to the moon
			return (0);
		}
	}
	return (0);
}
