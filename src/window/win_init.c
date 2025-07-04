/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 04:07:48 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/07/04 15:04:05 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <stdlib.h>

static int	init_keys(t_mlx *mlx)
{
	mlx->keys = ft_calloc_c(1, sizeof(t_keys));
	if (!mlx->keys)
		return (0);
	return (1);
}

static int	init_mainframe(t_data *data)
{
	t_image	*mainframe_img;

	mainframe_img = ft_calloc_c(1, sizeof(t_image));
	if (!mainframe_img)
		return (0);
	mainframe_img->width = SCREEN_WIDTH;
	mainframe_img->height = SCREEN_HEIGHT;
	mainframe_img->img_ptr = mlx_new_image(data->mlx->mlx_ptr,
			mainframe_img->width, mainframe_img->height);
	if (!mainframe_img->img_ptr)
		return (0);
	mainframe_img->data_addr = mlx_get_data_addr(mainframe_img->img_ptr,
			&mainframe_img->bpp, &mainframe_img->size_line,
			&mainframe_img->endian);
	data->mlx->mainframe_img = mainframe_img;
	return (1);
}

int	init_mlx(t_data *data)
{
	data->mlx = ft_calloc_c(1, sizeof(t_mlx));
	if (!data->mlx)
		return (0);
	data->mlx->mlx_ptr = mlx_init();
	if (!data->mlx->mlx_ptr)
		return (0);
	return (1);
}

int	init_win(t_data *data)
{
	data->mlx->win_ptr = mlx_new_window(data->mlx->mlx_ptr,
			SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
	if (!data->mlx->win_ptr || !init_keys(data->mlx)
		|| !init_mainframe(data))
		return (0);
	init_hooks(data);
	return (1);
}
