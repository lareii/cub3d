/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:25:11 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/28 14:25:54 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_movement(t_data *data)
{
	double	move_speed = data->mlx->frame_time * MOVE_SPEED_FACTOR;
	double	new_x, new_y;
	double	pos_x = data->player->pos_x;
	double	pos_y = data->player->pos_y;
	double	dir_x = data->player->dir_x;
	double	dir_y = data->player->dir_y;

	if (data->mlx->keys->key_w)
	{
		new_x = pos_x + dir_x * move_speed;
		new_y = pos_y + dir_y * move_speed;
		if (data->map->data[(int)pos_y][(int)new_x] != '1')
			data->player->pos_x = new_x;
		if (data->map->data[(int)new_y][(int)pos_x] != '1')
			data->player->pos_y = new_y;
	}
	if (data->mlx->keys->key_a)
	{
		new_x = pos_x + dir_y * move_speed;
		new_y = pos_y - dir_x * move_speed;
		if (data->map->data[(int)pos_y][(int)new_x] != '1')
			data->player->pos_x = new_x;
		if (data->map->data[(int)new_y][(int)pos_x] != '1')
			data->player->pos_y = new_y;
	}
	if (data->mlx->keys->key_s)
	{
		new_x = pos_x - dir_x * move_speed;
		new_y = pos_y - dir_y * move_speed;
		if (data->map->data[(int)pos_y][(int)new_x] != '1')
			data->player->pos_x = new_x;
		if (data->map->data[(int)new_y][(int)pos_x] != '1')
			data->player->pos_y = new_y;
	}
	if (data->mlx->keys->key_d)
	{
		new_x = pos_x - dir_y * move_speed;
		new_y = pos_y + dir_x * move_speed;
		if (data->map->data[(int)pos_y][(int)new_x] != '1')
			data->player->pos_x = new_x;
		if (data->map->data[(int)new_y][(int)pos_x] != '1')
			data->player->pos_y = new_y;
	}
}

// static void handle_movement_keys(t_data *data, double move_speed, int sign_x, int sign_y)
// {
// 	double	new_x;
// 	double	new_y;

// 	new_x = data->player->pos_x + ((data->player->dir_x * move_speed) * sign_x);
// 	new_y = data->player->pos_y + ((data->player->dir_y * move_speed) * sign_y);
// 	if (data->map->data[(int)data->player->pos_y][(int)new_x] != '1')
// 		data->player->pos_x = new_x;
// 	if (data->map->data[(int)new_y][(int)data->player->pos_x] != '1')
// 		data->player->pos_y = new_y;
// }

// void	handle_movement(t_data *data)
// {
// 	double	move_speed = data->mlx->frame_time * MOVE_SPEED_FACTOR;

// 	if (data->mlx->keys->key_w)
// 		handle_movement_keys(data, move_speed, 1, 1);
// 	if (data->mlx->keys->key_a)
// 		handle_movement_keys(data, move_speed, 1, -1);
// 	if (data->mlx->keys->key_s)
// 		handle_movement_keys(data, move_speed, -1, -1);
// 	if (data->mlx->keys->key_d)
// 		handle_movement_keys(data, move_speed, -1, 1);
// }