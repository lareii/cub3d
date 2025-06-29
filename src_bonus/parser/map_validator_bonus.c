/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:08:23 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/30 01:37:53 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
			else if (item != ' ' && item != '1' && item != '0' && item != 'D')
				return (0);
			x++;
		}
		y++;
	}
	return (player_count == 1);
}

static int	check_position(t_map *map, size_t x, size_t y)
{
	if (x == 0 || x == ft_strlen_c(map->data[y]) - 1
		|| y == 0 || y == map->height - 1)
		return (0);
	if (map->data[y - 1][x] == ' ' || map->data[y + 1][x] == ' '
		|| map->data[y][x - 1] == ' ' || map->data[y][x + 1] == ' ')
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
			if (map->data[y][x] == '0' || map->data[y][x] == 'D')
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
