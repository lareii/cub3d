/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:12:14 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/28 15:35:43 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_vertical_line(t_image *img, t_ray *ray, size_t x)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	y;

	line_height = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
	draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw_end >= SCREEN_WIDTH)
		draw_end = SCREEN_HEIGHT - 1;
	y = draw_start;
	while (y <= draw_end)
	{
		draw_pixel_on_image(img, 0xFF0000, x, y);
		y++;
	}
}

void	raycaster(t_data *data)
{
	t_player	*p;
	t_ray		ray;
	size_t		x;

	p = data->player;
	x = 0;
	draw_floor_and_ceiling(data);
	while (x < SCREEN_WIDTH)
	{
		perform_dda(&ray, data->map->data, p, x);
		draw_vertical_line(data->mlx->mainframe_img, &ray, x);
		x++;
	}
}
