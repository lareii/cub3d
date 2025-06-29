/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 20:22:38 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/29 16:08:52 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	set_player_direction(t_data *data, char direction)
{
	if (direction == 'N')
	{
		data->player->dir_x = 0;
		data->player->dir_y = -1;
	}
	else if (direction == 'S')
	{
		data->player->dir_x = 0;
		data->player->dir_y = 1;
	}
	else if (direction == 'W')
	{
		data->player->dir_x = -1;
		data->player->dir_y = 0;
	}
	else if (direction == 'E')
	{
		data->player->dir_x = 1;
		data->player->dir_y = 0;
	}
}

static int	set_player_position(t_data *data, size_t x, size_t y)
{
	if (x >= data->map->width || y >= data->map->height)
		return (0);
	data->player->pos_x = x + 0.5;
	data->player->pos_y = y + 0.5;
	return (1);
}

// fov_deg = 66.0;
// fov_rad = fov_deg * M_PI / 180.0;
// plane_len = tan(fov_rad / 2.0); ≈ 0.66
int	init_player(t_data *data, size_t x, size_t y)
{
	data->player = ft_calloc_c(1, sizeof(t_player));
	if (!data->player)
		return (0);
	set_player_direction(data, data->map->data[y][x]);
	data->player->plane_x = -data->player->dir_y * tan(FOV / 2.0 * PI / 180.0);
	data->player->plane_y = data->player->dir_x * tan(FOV / 2.0 * PI / 180.0);
	data->map->data[y][x] = '0';
	if (!set_player_position(data, x, y))
		return (0);
	return (1);
}
