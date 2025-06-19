/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 01:26:50 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/19 17:03:57 by ahekinci         ###   ########.fr       */
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

// void	draw_circle_on_image(t_image *img, t_circle *circle)
// {
// 	int	i;
// 	int	j;

// 	i = -(circle->radius);
// 	if (circle->radius <= 0)
// 		return ;
// 	while (i <= circle->radius)
// 	{
// 		j = -(circle->radius);
// 		while (j <= circle->radius)
// 		{
// 			if (i * i + j * j <= circle->radius * circle->radius)
// 				draw_pixel_on_image(img, circle->color, circle->x + i, circle->y + j);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	draw_circle_on_image(t_image *img, t_circle *circle)
{
	int i, j;
	for (i = -circle->radius; i <= circle->radius; i++)
	{
		for (j = -circle->radius; j <= circle->radius; j++)
		{
			if (i*i + j*j <= circle->radius*circle->radius)
				draw_pixel_on_image(img, circle->color, circle->x + i, circle->y + j);
		}
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
