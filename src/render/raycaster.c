/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:12:14 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/29 15:40:49 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	init_texture_render_data(t_data *data, t_ray *ray)
{
	ray->line_height = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_end >= SCREEN_HEIGHT)
		ray->draw_end = SCREEN_HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = data->player->pos_y
			+ ray->perp_wall_dist * ray->dir_y;
	else
		ray->wall_x = data->player->pos_x
			+ ray->perp_wall_dist * ray->dir_x;
	ray->wall_x -= (int)ray->wall_x;
}

void	select_wall_texture(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			ray->texture = data->textures->west;
		else
			ray->texture = data->textures->east;
	}
	else
	{
		if (ray->dir_y > 0)
			ray->texture = data->textures->north;
		else
			ray->texture = data->textures->south;
	}
}

void	compute_texture_coords(t_ray *ray)
{
	ray->tex_x = (int)(ray->wall_x * ray->texture->width);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		ray->tex_x = ray->texture->width - ray->tex_x - 1;
	ray->tex_step = 1.0 * ray->texture->height / ray->line_height;
	ray->tex_pos = (ray->draw_start - SCREEN_HEIGHT / 2
			+ ray->line_height / 2) * ray->tex_step;
}

void	raycaster(t_data *data)
{
	t_player	*p;
	t_ray		ray;
	size_t		x;

	p = data->player;
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		perform_dda(&ray, data->map->data, p, x);
		draw_vertical_line(data, &ray, x);
		x++;
	}
}
