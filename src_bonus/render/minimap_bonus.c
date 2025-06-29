/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:20:28 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/29 21:31:29 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "mlx.h"
#include <stdio.h>

static int	double_to_scaled_int(double value, int scale)
{
	return (int)(value * scale);
}

void	draw_map_on_image(t_data *data)
{
	int x = double_to_scaled_int(data->player->pos_x, 10);
	int y = double_to_scaled_int(data->player->pos_y, 10);

	draw_rectangle_on_image(data->mlx->minimap_img, &(t_rectangle){
			.x = MINIMAP_WIDTH / 2 + (x / 10),
			.y = MINIMAP_HEIGHT / 2 + (y / 10),
			.width = MINIMAP_WIDTH,
			.height = MINIMAP_HEIGHT,
			.color = MINIMAP_BACK_COLOR
		});
}


