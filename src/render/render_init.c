/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 04:57:39 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/22 06:34:48 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_data *data)
{
	t_player	player;
	t_map		map;

	char maps[24][24] = {
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

	player.posX = 0;
	player.posY = 0;

	map.width = 24;
	map.height = 24;
	copy_map_to_struct(24, 24, maps, &map);
	find_player_position(&map, &player);
	data->map = &map;
	data->player = &player;
}

int	game_loop(t_data *data)
{
	if (data->mlx->keys->key_w) // fix for raycasing thats emirhan's job idk
		data->player->posY -= MOVE_SPEED_FACTOR;
	if (data->mlx->keys->key_s)
		data->player->posY += MOVE_SPEED_FACTOR;
	if (data->mlx->keys->key_a)
		data->player->posX -= MOVE_SPEED_FACTOR;
	if (data->mlx->keys->key_d)
		data->player->posX += MOVE_SPEED_FACTOR;

	render(data);
	return 0;
}
