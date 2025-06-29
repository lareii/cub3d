/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:05:10 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/30 01:59:04 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d_bonus.h"
#include <stdio.h>

static int	render(t_data *data)
{
	data->mlx->oldtime = data->mlx->time;
	data->mlx->time = get_time_in_seconds();
	data->mlx->frame_time = data->mlx->time - data->mlx->oldtime;
	printf("fps: %f\n", 1.0 / data->mlx->frame_time);
	raycaster(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
		data->mlx->mainframe_img->img_ptr, 0, 0);
	draw_map_on_image(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
		data->mlx->minimap_img->img_ptr, 0, 0);
	if (data->mlx->keys->is_mouse_locked)
	{
		#if defined(__linux__)
		mlx_mouse_move(data->mlx->mlx_ptr, data->mlx->win_ptr,
			SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		#else
		mlx_mouse_move(data->mlx->win_ptr,
			SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		#endif
	}
	return (1);
}

int	game_loop(t_data *data)
{
	handle_movement(data);
	handle_rotation(data);
	if (!render(data))
		return (0);
	return (0);
}
