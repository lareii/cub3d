/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:05:10 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/26 15:36:34 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"
#include <stdlib.h>

// malloc surekli yapma img structi icin mal. bir kere yap kullan, yenisi lazim oldugunda da yeni initilzation yap
int	init_image(t_data *data, t_image **image, int w, int h)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	if (!img)
		return (0);
	*image = img;
	img->width = w;
	img->height = h;
	img->img_ptr = mlx_new_image(data->mlx->mlx_ptr, w, h);
	if (!img->img_ptr)
		return (0);
	img->data_addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_line, &img->endian);
	return (1);
}

static int	render(t_data *data)
{
	if (!init_image(data, &data->mlx->mainframe_img, SCREEN_WIDTH, SCREEN_HEIGHT))
		return (0);
	raycaster(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr, data->mlx->mainframe_img->img_ptr, 0, 0);
	mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->mainframe_img->img_ptr);
	free(data->mlx->mainframe_img);
	return (1);
}

int	game_loop(t_data *data)
{
	if (!render(data))
		return (0);
	return (0);
}

