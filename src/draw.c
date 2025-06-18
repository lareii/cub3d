/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 01:26:50 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/19 02:25:42 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"

void draw_pixel_on_image(t_data *data, int color, int x, int y)
{
	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return;
	char *dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void draw_circle_on_image(t_data *data, int radius, int x, int y)
{
	int i = -radius;
	while (i <= radius)
	{
		int j = -radius;
		while (j <= radius)
		{
			if (i * i + j * j <= radius * radius)
				draw_pixel_on_image(data, CIRCLE_COLOR, x + i, y + j);
			j++;
		}
		i++;
	}
}

