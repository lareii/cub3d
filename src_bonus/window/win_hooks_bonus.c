/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 04:40:28 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/07/04 15:35:21 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "mlx.h"
#include <stdlib.h>

static int	destroy_handler(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx_ptr);
	return (0);
}

static int	key_press(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_W)
		mlx->keys->key_w = 1;
	if (keycode == KEY_A)
		mlx->keys->key_a = 1;
	if (keycode == KEY_S)
		mlx->keys->key_s = 1;
	if (keycode == KEY_D)
		mlx->keys->key_d = 1;
	if (keycode == KEY_LEFT)
		mlx->keys->key_left = 1;
	if (keycode == KEY_RIGHT)
		mlx->keys->key_right = 1;
	return (0);
}

static int	key_release(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_W)
		mlx->keys->key_w = 0;
	if (keycode == KEY_A)
		mlx->keys->key_a = 0;
	if (keycode == KEY_S)
		mlx->keys->key_s = 0;
	if (keycode == KEY_D)
		mlx->keys->key_d = 0;
	if (keycode == KEY_L)
		mlx->keys->is_mouse_locked = !mlx->keys->is_mouse_locked;
	if (keycode == KEY_LEFT)
		mlx->keys->key_left = 0;
	if (keycode == KEY_RIGHT)
		mlx->keys->key_right = 0;
	if (keycode == KEY_ESC)
		destroy_handler(mlx);
	return (0);
}

static int	mouse_move(int x, int y, t_mlx *mlx)
{
	int	delta_x;

	(void)y;
	delta_x = x - (SCREEN_WIDTH / 2);
	mlx->keys->mouse_delta_x = delta_x;
	return (0);
}

void	init_hooks(t_data *data)
{
	mlx_hook(data->mlx->win_ptr, 17, 0, destroy_handler, data->mlx);
	mlx_hook(data->mlx->win_ptr, 2, 1L << 0, key_press, data->mlx);
	mlx_hook(data->mlx->win_ptr, 3, 1L << 1, key_release, data->mlx);
	mlx_hook(data->mlx->win_ptr, 6, 1L << 6, mouse_move, data->mlx);
	mlx_loop_hook(data->mlx->mlx_ptr, game_loop, data);
	mlx_loop(data->mlx->mlx_ptr);
}
