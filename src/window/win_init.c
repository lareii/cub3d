/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 04:07:48 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/28 17:37:27 by ahekinci         ###   ########.fr       */
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

static int	init_images(t_data *data)
{
	data->mlx->mainframe_img = malloc(sizeof(t_image));
	if (!data->mlx->mainframe_img)
		return (0);
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
		|| !init_images(data))
		return (0);
	init_hooks(data);
	return (1);
}
