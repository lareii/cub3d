/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:20:28 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/29 18:42:14 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_map_on_image(t_data *data)
{
	int tiles_x = MINIMAP_WIDTH / MINIMAP_TITLE_SIZE;
	int tiles_y = MINIMAP_HEIGHT / MINIMAP_TITLE_SIZE;

	int y = 0;
	int x = 0;

	int map_x = 0;
	int map_y = 0;

	double start_x = data->player->pos_x - tiles_x / 2.0;
	double start_y = data->player->pos_y - tiles_y / 2.0;

	while (y < tiles_y)
	{
		x = 0;
		while (x < tiles_x)
		{
			map_x = (int)(start_x + x);
			map_y = (int)(start_y + y);

			if (map_x < 0 || map_y < 0 || map_y >= (int)data->map->height || map_x >= (int)data->map->width)
				continue;

			if (data->map->data[map_y][map_x] == '1')
				draw_rectangle_on_image(data->mlx->minimap_img,
					&(t_rectangle){.x = x * MINIMAP_TITLE_SIZE,
					.y = y * MINIMAP_TITLE_SIZE,
					.width = MINIMAP_TITLE_SIZE,
					.height = MINIMAP_TITLE_SIZE,
					.color = MINIMAP_WALL_COLOR});
			else if (data->map->data[map_y][map_x] == '0')
				draw_rectangle_on_image(data->mlx->minimap_img,
					&(t_rectangle){.x = x * MINIMAP_TITLE_SIZE,
					.y = y * MINIMAP_TITLE_SIZE,
					.width = MINIMAP_TITLE_SIZE,
					.height = MINIMAP_TITLE_SIZE,
					.color = MINIMAP_BACK_COLOR});
		}

		y++;
	}
	draw_circle_on_image(data->mlx->minimap_img,
		&(t_circle){.x = (int)(data->player->pos_x - start_x) * MINIMAP_TITLE_SIZE,
		.y = (int)(data->player->pos_y - start_y) * MINIMAP_TITLE_SIZE,
		.radius = MINIMAP_PLAYER_RADIUS,
		.color = MINIMAP_PLAYER_COLOR});
	
}