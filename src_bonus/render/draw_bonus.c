/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:51:05 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/29 16:08:57 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_pixel_on_image(t_image *img, int color, int x, int y)
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
