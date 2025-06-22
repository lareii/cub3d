/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 04:40:28 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/22 04:46:15 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

int	destroy_handler(t_mlx *mlx)
{
	#if defined(__linux__)
		mlx_loop_end(mlx->mlx_ptr); // temporary solution
	#else
		exit(1);
	#endif
	return (0);
}

int key_press(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->mlx->keys->key_w = 1;
	if (keycode == KEY_A)
		data->mlx->keys->key_a = 1;
	if (keycode == KEY_S)
		data->mlx->keys->key_s = 1;
	if (keycode == KEY_D)
		data->mlx->keys->key_d = 1;
	return (0);
}

int key_release(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->mlx->keys->key_w = 0;
	if (keycode == KEY_A)
		data->mlx->keys->key_a = 0;
	if (keycode == KEY_S)
		data->mlx->keys->key_s = 0;
	if (keycode == KEY_D)
		data->mlx->keys->key_d = 0;
	if (keycode == KEY_ESC)
		destroy_handler(data->mlx);
	return (0);
}
