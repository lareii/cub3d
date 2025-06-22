/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 23:53:22 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/21 22:04:38 by ahekinci         ###   ########.fr       */
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