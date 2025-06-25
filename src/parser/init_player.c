/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 20:22:38 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/25 22:03:08 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_direction(t_data *data, char direction)
{
	if (direction == 'N')
	{
		data->player->dir_x = -1;
		data->player->dir_y = 0;
	}
	else if (direction == 'S')
	{
		data->player->dir_x = 1;
		data->player->dir_y = 0;
	}
	else if (direction == 'W')
	{
		data->player->dir_x = 0;
		data->player->dir_y = -1;
	}
	else if (direction == 'E')
	{
		data->player->dir_x = 0;
		data->player->dir_y = 1;
	}
}

int	set_player_position(t_data *data, size_t x, size_t y)
{
	if (x >= data->map->width || y >= data->map->height)
		return (0);
	data->player->pos_x = x + 0.5;
	data->player->pos_y = y + 0.5;
	return (1);
}

int	init_player(t_data *data, size_t x, size_t y)
{
	data->player = ft_calloc_c(1, sizeof(t_player));
	if (!data->player)
		return (0);
	data->player->plane_x = 0;
	data->player->plane_y = 0.66;
	set_player_direction(data, data->map->data[y][x]);
	data->map->data[y][x] = '0';
	if (!set_player_position(data, x, y))
		return (0);
	return (1);
}
