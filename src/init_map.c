/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 23:53:22 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/22 05:48:18 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void copy_map_to_struct(int height, int width, char src[height][width], t_map *dest) //temporary solution
{
	dest->height = height;
	dest->width = width;
	dest->data = malloc(height * sizeof(char *));
	for (int i = 0; i < height; i++) {
		dest->data[i] = malloc(width + 1);
		memcpy(dest->data[i], src[i], width);
		dest->data[i][width] = '\0';
	}
}

void find_player_position(t_map *map, t_player *player)
{
	for (int i = 0; i < map->height; i++) {
		for (int j = 0; j < map->width; j++) { 
			if (map->data[i][j] == 'P') {
				player->posX = j;
				player->posY = i;
				return;
			}
		}
	}
}