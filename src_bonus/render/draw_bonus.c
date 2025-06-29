/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:51:05 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/30 00:06:09 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_pixel_on_image(t_image *img, int color, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	dst = img->data_addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_texture_line(t_image *img, t_ray *ray, int x, int y)
{
	int		tex_y;
	int		color;
	char	*pixel;

	tex_y = (int)ray->tex_pos;
	if (tex_y >= ray->texture->height)
		tex_y = ray->texture->height - 1;
	ray->tex_pos += ray->tex_step;
	pixel = ray->texture->data_addr
		+ (tex_y * ray->texture->size_line
			+ ray->tex_x * (ray->texture->bpp / 8));
	color = *(unsigned int *)pixel;
	draw_pixel_on_image(img, color, x, y);
}

void	draw_vertical_line(t_data *data, t_ray *ray, size_t x)
{
	int	y;

	init_texture_render_data(data, ray);
	select_wall_texture(data, ray);
	compute_texture_coords(ray);
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		if (y < ray->draw_start)
			draw_pixel_on_image(data->mlx->mainframe_img,
				data->textures->ceiling, x, y);
		else if (y <= ray->draw_end)
			draw_texture_line(data->mlx->mainframe_img, ray, x, y);
		else
			draw_pixel_on_image(data->mlx->mainframe_img,
				data->textures->floor, x, y);
		y++;
	}
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
				draw_pixel_on_image(img, circle->color,
					circle->x + i, circle->y + j);
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
