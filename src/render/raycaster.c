/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:12:14 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/26 17:43:50 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	set_ray_direction(t_ray *ray, t_player *player, int x)
{
	ray->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
}

static void	init_ray(t_ray *ray, t_player *player)
{
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->hit = 0;
}

static void	init_steps_and_deltas(t_ray *ray, t_player *player)
{
	if (ray->dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->dir_y);
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y) * ray->delta_dist_y;
	}
}

static void	perform_dda(t_ray *ray, char **map)
{
	while (!ray->hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if ((size_t)ray->map_x >= ft_strlen_c(map[ray->map_y])
			|| map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
}

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

static void	draw_floor_and_ceiling(t_data *data)
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
				draw_pixel_on_image(data->mlx->mainframe_img, data->textures->ceiling, x, y);
			else
				draw_pixel_on_image(data->mlx->mainframe_img, data->textures->floor, x, y);
			x++;
		}
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
		set_ray_direction(&ray, p, x);
		init_ray(&ray, p);
		init_steps_and_deltas(&ray, p);
		perform_dda(&ray, data->map->data);
		draw_vertical_line(data->mlx->mainframe_img, &ray, x);
		x++;
	}
}

/*

        ^ N
        |
        |
E <---- o -----> W
        |
        |
        V S

*/