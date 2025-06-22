/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 05:01:08 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/22 06:33:06 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

void	render(t_data *data)
{
	t_image		image;

	image.width = SCREEN_WIDTH;
	image.height = SCREEN_HEIGHT;
	data->mlx->mainframe_img = &image;
	data->mlx->mainframe_img->img_ptr = mlx_new_image(data->mlx->mlx_ptr, data->mlx->mainframe_img->width, data->mlx->mainframe_img->height);
	data->mlx->mainframe_img->data_addr = mlx_get_data_addr(data->mlx->mainframe_img->img_ptr, &data->mlx->mainframe_img->bpp, &data->mlx->mainframe_img->size_line, &data->mlx->mainframe_img->endian);
	draw_map_on_image(data);
	draw_circle_on_image(data->mlx->mainframe_img, &(t_circle){.x = SCREEN_WIDTH / 2, .y = SCREEN_HEIGHT / 2, .radius = 10, .color = 0xFF0000});
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr, data->mlx->mainframe_img->img_ptr, 0, 0);
	// draw_text(data);
	mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->mainframe_img->img_ptr);
}