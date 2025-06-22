/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 22:04:45 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/21 22:06:25 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

//keys mac
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_ESC 53
#define KEY_W 13

//keys linux
// #define KEY_W 119
// #define KEY_A 97
// #define KEY_S 115
// #define KEY_D 100
// #define KEY_ESC 65307

int key_press(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->key_status.key_w = true;
	if (keycode == KEY_A)
		data->key_status.key_a = true;
	if (keycode == KEY_S)
		data->key_status.key_s = true;
	if (keycode == KEY_D)
		data->key_status.key_d = true;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return 0;
}

int key_release(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->key_status.key_w = false;
	if (keycode == KEY_A)
		data->key_status.key_a = false;
	if (keycode == KEY_S)
		data->key_status.key_s = false;
	if (keycode == KEY_D)
		data->key_status.key_d = false;
	return 0;
}