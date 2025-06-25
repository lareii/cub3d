/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:16:11 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/25 20:43:43 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"
#include <stdlib.h>

static int	skip_newlines(int fd, char **line)
{
	while (1)
	{
		*line = get_next_line(fd);
		if (!*line)
		{
			get_next_line(-1);
			return (0);
		}
		if (*line[0] != '\n')
			break ;
		free(*line);
	}
	return (1);
}

// int	init_map_data(t_map *map, int fd)
// {
// 	char	*line;
// 	char	*trimmed;

// 	if (!skip_newlines(fd, &line))
// 		return (0);
// 	map->height = 1;
// 	while (1)
// 	{
// 		if (!(line[0] == '1' || line[0] == ' '))
// 		{
// 			free(line);
// 			get_next_line(-1);
// 			return (0);
// 		}
// 		trimmed = ft_strtrim(line, "\n");
// 		if (!trimmed)
// 		{
// 			free(line);
// 			get_next_line(-1);
// 			return (0);
// 		}
// 		map->data = str_arr_join(map->data, trimmed);
// 		if (!map->data)
// 		{
// 			free(trimmed);
// 			free(line);
// 			get_next_line(-1);
// 			return (0);
// 		}
// 		free(line);
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		if (map->width < ft_strlen_c(trimmed))
// 			map->width = ft_strlen_c(trimmed);
// 		map->height++;
// 	}
// 	get_next_line(-1);
// 	return (1);
// }

static int	append_map_line(t_map *map, char *line)
{
	char	*trimmed;

	trimmed = ft_strtrim(line, "\n");
	if (!trimmed)
		return (0);
	map->data = str_arr_join(map->data, trimmed);
	if (!map->data)
	{
		free(trimmed);
		return (0);
	}
	if (map->width < ft_strlen_c(trimmed))
		map->width = ft_strlen_c(trimmed);
	return (1);
}

int	init_map_data(t_map *map, int fd)
{
	char	*line;

	if (!skip_newlines(fd, &line))
		return (0);
	map->height = 1;
	while (line)
	{
		if ((line[0] != '1' && line[0] != ' ') || !append_map_line(map, line))
		{
			free(line);
			get_next_line(-1);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
		if (line)
			map->height++;
	}
	get_next_line(-1);
	return (1);
}
