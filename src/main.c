/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 02:26:04 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/22 03:20:41 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "mlx.h"
#include "cub3d.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "sys/time.h"

#include <string.h>

void render(t_data *data);

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

void render(t_data *data)
{
	data->img.img = mlx_new_image(data->mlx, data->img.width, data->img.height);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, &data->img.line_length, &data->img.endian);
	draw_map_on_image(data);
	draw_circle_on_image(&(data->img), &(t_circle){.x = SCREEN_WIDTH / 2, .y = SCREEN_HEIGHT / 2, .radius = 10, .color = COLOR});
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	draw_text(data);
	mlx_destroy_image(data->mlx, data->img.img);
}

void find_player_position(t_map *map, int *x, int *y)
{
	for (int i = 0; i < map->height; i++) {
		for (int j = 0; j < map->width; j++) { 
			if (map->data[i][j] == 'P') {
				*x = j;
				*y = i;
				return;
			}
		}
	}
	// If player not found, set to -1
	*x = -1;
	*y = -1;
}

int main(void)
{
	t_data data;

	// char map[5][7] = {
	// 	{'1', '1', '1', '1', '1', '1', '1'},
	// 	{'1', '0', '0', '0', '0', '0', '1'},
	// 	{'1', '0', '1', '0', '0', '0', '1'},
	// 	{'1', '0', '0', '0', '0', 'P', '1'},
	// 	{'1', '1', '1', '1', '1', '1', '1'}
	// };

	// copy_map_to_struct(5, 7, map, &data.map);

	char map[24][24] = {
		{"111111111111111111111111"},
		{"100000000000000000000001"},
		{"100000000000000000000001"},
		{"10000P000000000000000001"},
		{"100000111110000101010001"},
		{"100000100010000000000001"},
		{"100000100010000100010001"},
		{"100000100010000000000001"},
		{"100000110110000101010001"},
		{"100000000000000000000001"},
		{"100000000000000000000001"},
		{"100000000000000000000001"},
		{"100000000000000000000001"},
		{"100000000000000000000001"},
		{"100000000000000000000001"},
		{"100000000000000000000001"},
		{"111111111000000000000001"},
		{"110100001000000000000001"},
		{"110000101000000000000001"},
		{"110100001000000000000001"},
		{"110111111000000000000001"},
		{"110000000000000000000001"},
		{"111111111000000000000001"},
		{"111111111111111111111111"}
	};

	copy_map_to_struct(24, 24, map, &data.map);

	// printf("data size: %zu\n", sizeof(data));

	find_player_position(&data.map, &data.x, &data.y);

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "not completed");
	data.x = data.x * TILE_SIZE + TILE_SIZE / 2; // Center the player in the tile
	data.y = data.y * TILE_SIZE + TILE_SIZE / 2; // Center the player in the tile

	// data.x = 0;
	// data.y = 0;

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