/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 04:07:48 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/22 05:56:10 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <stddef.h>

static void	init_keys(t_mlx *mlx)
{
	t_keys	keys;
	
	keys.key_w = 0;
	keys.key_a = 0;
	keys.key_s = 0;
	keys.key_d = 0;
	mlx->keys = &keys;
}

int	init_win(t_data *data)
{
	t_mlx	mlx;

	mlx.mlx_ptr = NULL;
	mlx.win_ptr = NULL;
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		return (0);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr,
		SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
	if (!mlx.win_ptr)
	{
		destroy_win(&mlx);
		return (0);
	}
	data->mlx = &mlx;
	init_player(data);
	init_keys(&mlx);
	mlx_hook(mlx.win_ptr, 17, 0, destroy_handler, &mlx);
	mlx_hook(mlx.win_ptr, 2, 1L << 0, key_press, data);
	mlx_hook(mlx.win_ptr, 3, 1L << 1, key_release, data);
	mlx_loop_hook(mlx.mlx_ptr, game_loop, data);
	mlx_loop(mlx.mlx_ptr);
	destroy_win(&mlx);
	return (1);
}
