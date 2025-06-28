/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:05:10 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/28 14:21:22 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int	init_image_data(t_data *data, t_image *img, int w, int h)
{
	img->width = w;
	img->height = h;
	img->img_ptr = mlx_new_image(data->mlx->mlx_ptr, w, h);
	if (!img->img_ptr)
		return (0);
	img->data_addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_line, &img->endian);
	return (1);
}

static int	render(t_data *data)
{
	data->mlx->oldtime = data->mlx->time;
	data->mlx->time = get_time_in_seconds();
	data->mlx->frame_time = data->mlx->time - data->mlx->oldtime;
	printf("fps: %f\n", 1.0 / data->mlx->frame_time);
	if (!init_image_data(data, data->mlx->mainframe_img, SCREEN_WIDTH, SCREEN_HEIGHT))
		return (0);
	raycaster(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr, data->mlx->mainframe_img->img_ptr, 0, 0);
	mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->mainframe_img->img_ptr);
	return (1);
}

static void	handle_rotation(t_data *data)
{
	double	rot_speed;
	double	old_dir_x;
	double	old_plane_x;

	rot_speed = data->mlx->frame_time * ROT_SPEED_FACTOR;
	if (data->mlx->keys->key_left)
	{
		old_dir_x = data->player->dir_x;
		old_plane_x = data->player->plane_x;
		data->player->dir_x = data->player->dir_x * cos(-rot_speed) - data->player->dir_y * sin(-rot_speed);
		data->player->dir_y = old_dir_x * sin(-rot_speed) + data->player->dir_y * cos(-rot_speed);
		data->player->plane_x = data->player->plane_x * cos(-rot_speed) - data->player->plane_y * sin(-rot_speed);
		data->player->plane_y = old_plane_x * sin(-rot_speed) + data->player->plane_y * cos(-rot_speed);
	}
	if (data->mlx->keys->key_right)
	{
		old_dir_x = data->player->dir_x;
		old_plane_x = data->player->plane_x;
		data->player->dir_x = data->player->dir_x * cos(rot_speed) - data->player->dir_y * sin(rot_speed);
		data->player->dir_y = old_dir_x * sin(rot_speed) + data->player->dir_y * cos(rot_speed);
		data->player->plane_x = data->player->plane_x * cos(rot_speed) - data->player->plane_y * sin(rot_speed);
		data->player->plane_y = old_plane_x * sin(rot_speed) + data->player->plane_y * cos(rot_speed);
	}
}


int	game_loop(t_data *data)
{
	handle_movement(data);
	handle_rotation(data);
	if (!render(data))
		return (0);
	return (0);
}

