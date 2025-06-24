/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:40:17 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/24 13:54:40 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <unistd.h>

#include <stdio.h>

static size_t	str_arr_len(char **arr)
{
	size_t	count;

	count = 0;
	while (arr && *arr)
	{
		arr++;
		count++;
	}
	return (count);
}

static char	**str_arr_join(char **arr, char *line)
{
	char	**new_arr;
	size_t	size;
	size_t	i;

	i = 0;
	size = str_arr_len(arr);
	new_arr = malloc(sizeof(char *) * (size + 2));
	if (!new_arr)
		return (NULL);
	while (i < size)
	{
		new_arr[i] = arr[i];
		i++;
	}
	new_arr[i] = line;
	new_arr[i + 1] = NULL;
	free(arr);
	return (new_arr);
}

static int	init_map_data(t_map *map, int fd)
{
	char	*line;
	
	map->data = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
		if (line[0] != '\n')
			break;
		free(line);
	}
	while (1)
	{
		// line = get_next_line(fd);
		// if (!line)
		// 	break ;
		printf("%s", line);
		if (!(line[0] == '1' || line[0] == ' '))
		{
			free(line);
			free_map(map);
			get_next_line(-1);
			return (0);
		}
		map->data = str_arr_join(map->data, line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	get_next_line(-1);
	return (1);
}

int	init_map(t_data *data, char **argv)
{	
	t_map	*map;
	int		fd;

	if (!filename_checker(argv[1]))
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	if (!init_map_textures(data, fd))
		return (0);
	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	data->map = map;
	if (!init_map_data(data->map, fd))
	{
		free_textures(data->textures);
		return (0);
	}
	close(fd);
	return (1);
}
