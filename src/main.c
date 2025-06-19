/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 02:26:04 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/19 17:03:46 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "mlx.h"
#include "cub3d.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "sys/time.h"

//keys mac
// #define KEY_A 0
// #define KEY_S 1
// #define KEY_D 2
// #define KEY_ESC 53
// #define KEY_W 13

//keys linux
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307

void render(t_data *data);


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

int game_loop(t_data *data)
{
	if (data->key_status.key_w)
		data->y -= MOVE_SPEED;
	if (data->key_status.key_s)
		data->y += MOVE_SPEED;
	if (data->key_status.key_a)
		data->x -= MOVE_SPEED;
	if (data->key_status.key_d)
		data->x += MOVE_SPEED;

	render(data);
	return 0;
}

// double get_time_in_seconds()
// {
// 	struct timeval tv;
// 	gettimeofday(&tv, NULL);
// 	return tv.tv_sec + tv.tv_usec / 1000000.0;
// }

void render(t_data *data)
{
	data->img.img = mlx_new_image(data->mlx, data->img.width, data->img.height);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, &data->img.line_length, &data->img.endian);
	draw_circle_on_image(&(data->img), &(t_circle){.x = data->x, .y = data->y, .radius = 20, .color = COLOR});
	mlx_put_image_to_window(data->mlx, data->win, data->img.addr, 0, 0);
	mlx_destroy_image(data->mlx, data->img.addr);
}

int main(void)
{
	t_data data;

	printf("data size: %zu\n", sizeof(data));

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "not completed");
	data.x = SCREEN_WIDTH / 2;
	data.y = SCREEN_HEIGHT / 2;

	data.img.width = SCREEN_WIDTH;
	data.img.height = SCREEN_HEIGHT;

	data.key_status.key_w = false;
	data.key_status.key_a = false;
	data.key_status.key_s = false;
	data.key_status.key_d = false;


	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_loop_hook(data.mlx, game_loop, &data);

	mlx_loop(data.mlx);
	return 0;
}