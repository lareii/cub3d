/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:16:11 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/29 14:59:26 by ebabaogl         ###   ########.fr       */
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

static int	go_to_eof(int fd)
{
	int		state;
	char	*line;

	state = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] != '\n')
		{
			state = 0;
			free(line);
			break ;
		}
		free(line);
	}
	return (state);
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
			if (line[0] == '\n' && go_to_eof(fd))
			{
				free(line);
				break ;
			}
			free(line);
			get_next_line(-1);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
		if (line && line[0] != '\n')
			map->height++;
	}
	get_next_line(-1);
	return (1);
}
