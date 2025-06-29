/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:20:28 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/30 00:16:35 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "mlx.h"

static void	clear_image(t_image *image)
{
	int	x;
	int	y;

	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			draw_pixel_on_image(image, MINIMAP_BACK_COLOR, x, y);
			x++;
		}
		y++;
	}
}

static void	draw_map_tile(t_data *data, int map_x, int map_y)
{
	int	screen_x;
	int	screen_y;

	screen_x = (MINIMAP_WIDTH / 2)
		+ (map_x - data->player->pos_x) * MINIMAP_TILE_SIZE;
	screen_y = (MINIMAP_HEIGHT / 2)
		+ (map_y - data->player->pos_y) * MINIMAP_TILE_SIZE;
	draw_rectangle_on_image(data->mlx->minimap_img,
		&(t_rectangle){.x = screen_x,
		.y = screen_y, .width = MINIMAP_TILE_SIZE,
		.height = MINIMAP_TILE_SIZE, .color = MINIMAP_WALL_COLOR});
}

void	draw_map_on_image(t_data *data)
{
	int	map_x;
	int	map_y;

	map_y = 0;
	clear_image(data->mlx->minimap_img);
	while (map_y < (int)data->map->height)
	{
		map_x = 0;
		while (map_x < (int)ft_strlen_c(data->map->data[map_y]))
		{
			if (data->map->data[map_y][map_x] == '1')
				draw_map_tile(data, map_x, map_y);
			map_x++;
		}
		map_y++;
	}
	draw_circle_on_image(data->mlx->minimap_img,
		&(t_circle){.x = (MINIMAP_WIDTH / 2),
		.y = (MINIMAP_HEIGHT / 2), .radius = MINIMAP_PLAYER_RADIUS,
		.color = MINIMAP_PLAYER_COLOR});
}
