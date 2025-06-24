/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:08:23 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/24 16:56:50 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int check_map_items(t_map *map)
{
	size_t	x;
	size_t	y;
	char	item;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->data[y][x] && x < map->width)
		{
			item = map->data[y][x];
			if (item != 'N' && item != 'S' && item != 'W' && item != 'E'
				&& item != ' ' && item != '1' && item != '0')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	map_validator(t_map *map)
{
	if (!check_map_items(map))
		return (0);
	return (1);
}
