/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:51:05 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/28 15:22:36 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_pixel_on_image(t_image *img, int color, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = img->data_addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_floor_and_ceiling(t_data *data)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if (y < SCREEN_HEIGHT / 2)
				draw_pixel_on_image(data->mlx->mainframe_img,
					data->textures->ceiling, x, y);
			else
				draw_pixel_on_image(data->mlx->mainframe_img,
					data->textures->floor, x, y);
			x++;
		}
		y++;
	}
}
