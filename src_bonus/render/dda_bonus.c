/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:04:49 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/30 01:34:30 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <math.h>

static void	init_ray(t_ray *ray, t_player *player, int x)
{
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->hit = 0;
	ray->camera_x = (2 * x / (double)SCREEN_WIDTH) - 1;
	ray->dir_x = player->dir_x + (player->plane_x * ray->camera_x);
	ray->dir_y = player->dir_y + (player->plane_y * ray->camera_x);
}

static void	init_deltas(t_ray *ray)
{
	if (ray->dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->dir_y);
}

static void	init_steps_and_deltas(t_ray *ray, t_player *player)
{
	init_deltas(ray);
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y)
			* ray->delta_dist_y;
	}
}

static int	is_valid_hit(char cell, t_ray *ray, t_player *player)
{
	double	dx;
	double	dy;
	double	dist;

	if (cell == '1')
		return (1);
	else if (cell == 'D')
	{
		dx = ray->map_x + 0.5 - player->pos_x;
		dy = ray->map_y + 0.5 - player->pos_y;
		dist = sqrt(dx * dx + dy * dy);
		if (dist >= 2.0)
			return (2);
	}
	return (0);
}

void	perform_dda(t_ray *ray, char **map, t_player *player, int x)
{
	char	cell;

	init_ray(ray, player, x);
	init_steps_and_deltas(ray, player);
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
		cell = map[ray->map_y][ray->map_x];
		ray->hit = is_valid_hit(cell, ray, player);
	}
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
}
