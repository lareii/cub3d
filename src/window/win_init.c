/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 04:07:48 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/22 19:27:42 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <stdlib.h>

static void	init_keys(t_mlx *mlx)
{
	mlx->keys = malloc(sizeof(t_keys));
	mlx->keys->key_w = 0;
	mlx->keys->key_a = 0;
	mlx->keys->key_s = 0;
	mlx->keys->key_d = 0;
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
	init_keys(data->mlx);
	init_hooks(data);
	destroy_win(data->mlx);
	return (1);
}
