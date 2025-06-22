/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 01:26:50 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/21 15:35:21 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"

#include "stdio.h"

void	draw_pixel_on_image(t_image *img, int color, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_circle_on_image(t_image *img, t_circle *circle)
{
	int	i;
	int	j;

	i = -(circle->radius);
	if (circle->radius <= 0)
		return ;
	while (i <= circle->radius)
	{
		j = -(circle->radius);
		while (j <= circle->radius)
		{
			if (i * i + j * j <= circle->radius * circle->radius)
				draw_pixel_on_image(img, circle->color, circle->x + i, circle->y + j);
			j++;
		}
		i++;
	}
}

void	draw_rectangle_on_image(t_image *img, t_rectangle *rect)
{
	int	i;
	int	j;

	if (rect->width <= 0 || rect->height <= 0)
		return ;
	i = 0;
	while (i < rect->height)
	{
		j = 0;
		while (j < rect->width)
		{
			draw_pixel_on_image(img, rect->color, rect->x + j, rect->y + i);
			j++;
		}
		i++;
	}
}

void	draw_map_on_image(t_data *data)
{
	t_rectangle rect;
	int			i;
	int			j;
	int			height_offset;
	int			width_offset;

	rect.width = TILE_SIZE;
	rect.height = TILE_SIZE;

	// height_offset = (data->img.height - (data->map.height * TILE_SIZE)) / 2;
	// width_offset = (data->img.width - (data->map.width * TILE_SIZE)) / 2;

	height_offset = SCREEN_HEIGHT / 2 - data->y;
	width_offset = SCREEN_WIDTH / 2 - data->x;

	for (i = 0; i < data->map.height; i++)
	{
		for (j = 0; j < data->map.width; j++)
		{
			if (data->map.data[i][j] == '1') // Assuming '1' represents a wall
			{
				rect.x = j * TILE_SIZE + width_offset;
				rect.y = i * TILE_SIZE + height_offset;
				rect.color = 0x40E0D0;
				draw_rectangle_on_image(&data->img, &rect);
			}
			else if (data->map.data[i][j] == '0') // Assuming '0' represents empty space
			{
				rect.x = j * TILE_SIZE + width_offset;
				rect.y = i * TILE_SIZE + height_offset;
				rect.color = 0xFFFFFF; // White for empty space
				draw_rectangle_on_image(&data->img, &rect);
			}
		}
	}
}

void draw_text(t_data *data)
{
	char str[50];
	snprintf(str, sizeof(str), "X: %d  Y: %d", data->x, data->y);
	mlx_string_put(data->mlx, data->win, SCREEN_WIDTH - 200, 20, 0xFFFFFF, str);
}
