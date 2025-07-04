/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 20:15:22 by ahekinci          #+#    #+#             */
/*   Updated: 2025/07/04 15:14:20 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <stddef.h>

static int	set_textures(t_data *data)
{
	data->textures = ft_calloc_c(1, sizeof(t_textures));
	if (!data->textures)
		return (0);
	data->textures->floor = -1;
	data->textures->ceiling = -1;
	return (1);
}

static int	set_texture_path(t_data *mlx, t_image **dir, char *line)
{
	t_image	*img;
	char	*path;

	if (!*dir)
	{
		path = ft_strtrim(line + 3, " \n");
		if (!path)
			return (0);
		img = ft_calloc_c(1, sizeof(t_image));
		if (!img)
			return (0);
		img->img_ptr = mlx_xpm_file_to_image(mlx->mlx->mlx_ptr, path,
				&img->width, &img->height);
		free(path);
		if (!img->img_ptr)
		{
			free(img);
			return (0);
		}
		img->data_addr = mlx_get_data_addr(img->img_ptr, &img->bpp,
				&img->size_line, &img->endian);
		*dir = img;
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
		return (set_texture_path(data, &data->textures->north, line));
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		return (set_texture_path(data, &data->textures->south, line));
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		return (set_texture_path(data, &data->textures->west, line));
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		return (set_texture_path(data, &data->textures->east, line));
	else if (line[0] == 'F' && line[1] == ' ')
	{
		data->textures->floor = str_to_rgb(ft_strtrim(line + 2, " \n"));
		return (data->textures->floor != -1);
	}
	else if (line[0] == 'C' && line[1] == ' ')
	{
		data->textures->ceiling = str_to_rgb(ft_strtrim(line + 2, " \n"));
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
	if (!all_textures_set(data->textures))
		return (0);
	return (1);
}
