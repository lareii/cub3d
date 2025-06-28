/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:25:11 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/28 15:35:35 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	handle_movement_keys(t_data *data, double move_speed,
	int sign_x, int sign_y)
{
	double	new_x;
	double	new_y;

	if (sign_x == sign_y)
	{
		new_x = data->player->pos_x
			+ ((data->player->dir_x * move_speed) * sign_x);
		new_y = data->player->pos_y
			+ ((data->player->dir_y * move_speed) * sign_y);
	}
	else
	{
		new_x = data->player->pos_x
			+ ((data->player->dir_y * move_speed) * sign_x);
		new_y = data->player->pos_y
			+ ((data->player->dir_x * move_speed) * sign_y);
	}
	if (data->map->data[(int)data->player->pos_y][(int)new_x] != '1')
		data->player->pos_x = new_x;
	if (data->map->data[(int)new_y][(int)data->player->pos_x] != '1')
		data->player->pos_y = new_y;
}

void	handle_movement(t_data *data)
{
	double	move_speed;

	move_speed = data->mlx->frame_time * MOVE_SPEED_FACTOR;
	if (data->mlx->keys->key_w)
		handle_movement_keys(data, move_speed, 1, 1);
	if (data->mlx->keys->key_a)
		handle_movement_keys(data, move_speed, 1, -1);
	if (data->mlx->keys->key_s)
		handle_movement_keys(data, move_speed, -1, -1);
	if (data->mlx->keys->key_d)
		handle_movement_keys(data, move_speed, -1, 1);
}

static void	calc_rotation(t_data *data, int sign)
{
	double	rot_speed;
	double	old_dir_x;
	double	old_plane_x;

	rot_speed = data->mlx->frame_time * ROT_SPEED_FACTOR;
	old_dir_x = data->player->dir_x;
	old_plane_x = data->player->plane_x;
	data->player->dir_x = data->player->dir_x * cos(sign * rot_speed)
		- data->player->dir_y * sin(sign * rot_speed);
	data->player->dir_y = old_dir_x * sin(sign * rot_speed)
		+ data->player->dir_y * cos(sign * rot_speed);
	data->player->plane_x = data->player->plane_x * cos(sign * rot_speed)
		- data->player->plane_y * sin(sign * rot_speed);
	data->player->plane_y = old_plane_x * sin(sign * rot_speed)
		+ data->player->plane_y * cos(sign * rot_speed);
}

void	handle_rotation(t_data *data)
{
	if (data->mlx->keys->key_left)
		calc_rotation(data, -1);
	if (data->mlx->keys->key_right)
		calc_rotation(data, 1);
}
