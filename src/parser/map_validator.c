/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:08:23 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/30 16:54:36 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_map_items(t_data *data)
{
	size_t	x;
	size_t	y;
	size_t	player_count;
	char	item;

	y = 0;
	player_count = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (data->map->data[y][x] && x < data->map->width)
		{
			item = data->map->data[y][x];
			if (item == 'N' || item == 'S' || item == 'W' || item == 'E')
			{
				if (player_count++ == 0 && !init_player(data, x, y))
					return (0);
			}
			else if (item != ' ' && item != '1' && item != '0')
				return (0);
			x++;
		}
		y++;
	}
	return (player_count == 1);
}

static int	check_position(t_map *map, size_t x, size_t y)
{
	size_t	len;

	len = ft_strlen_c(map->data[y]);
	if (y == 0 || y + 1 >= map->height || x == 0 || x + 1 >= len)
		return (0);
	if (x >= ft_strlen_c(map->data[y - 1]) || map->data[y - 1][x] == ' ')
		return (0);
	if (x >= ft_strlen_c(map->data[y + 1]) || map->data[y + 1][x] == ' ')
		return (0);
	if (x - 1 >= ft_strlen_c(map->data[y]) || map->data[y][x - 1] == ' ')
		return (0);
	if (x + 1 >= ft_strlen_c(map->data[y]) || map->data[y][x + 1] == ' ')
		return (0);
	return (1);
}

static int	check_map_walls(t_map *map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < ft_strlen_c(map->data[y]))
		{
			if (map->data[y][x] == '0')
			{
				if (!check_position(map, x, y))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	map_validator(t_data *data)
{
	if (!check_map_items(data))
		return (0);
	if (!check_map_walls(data->map))
		return (0);
	return (1);
}
