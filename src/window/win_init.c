/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 04:07:48 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/22 19:44:24 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <stdlib.h>

static int	init_keys(t_mlx *mlx)
{
	mlx->keys = malloc(sizeof(t_keys));
	if (!mlx->keys)
		return (0);
	mlx->keys->key_w = 0;
	mlx->keys->key_a = 0;
	mlx->keys->key_s = 0;
	mlx->keys->key_d = 0;
	return (1);
}

int	init_win(t_data *data)
{
	data->mlx = malloc(sizeof(t_mlx));
	if (!data->mlx)
		return (0);
	data->mlx->mlx_ptr = mlx_init();
	if (!data->mlx->mlx_ptr)
	{
		destroy_win(data->mlx);
		return (0);
	}
	data->mlx->win_ptr = mlx_new_window(data->mlx->mlx_ptr,
			SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
	if (!data->mlx->win_ptr)
	{
		destroy_win(data->mlx);
		return (0);
	}
	if (!init_keys(data->mlx))
	{
		destroy_win(data->mlx);
		return (0);
	}
	init_hooks(data);
	destroy_win(data->mlx);
	return (1);
}
