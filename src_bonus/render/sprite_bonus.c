/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 01:40:08 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/30 02:21:59 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

#define NONE 0xFF000000

void	blend_torch_scaled_onto_frame(t_image *frame, t_image *torch, int draw_width, int draw_height)
{
	int				x;
	int				y;
	int				src_x;
	int				src_y;
	int				dst_x;
	int				dst_y;
	float			scale_x;
	float			scale_y;
	unsigned int	color;
	char			*src_pixel;

	scale_x = (float)torch->width / draw_width;
	scale_y = (float)torch->height / draw_height;
	y = 0;
	while (y < draw_height)
	{
		x = 0;
		while (x < draw_width)
		{
			src_x = (int)(x * scale_x);
			src_y = (int)(y * scale_y);
			src_pixel = torch->data_addr
				+ (src_y * torch->size_line + src_x * (torch->bpp / 8));
			color = *(unsigned int *)src_pixel;
			if (color != NONE)
			{
				dst_x = x;
				dst_y = frame->height - draw_height + y;
				draw_pixel_on_image(frame, color, dst_x, dst_y);
			}
			x++;
		}
		y++;
	}
}

int	init_bonus_textures(t_data *data)
{
	set_texture_path(data, &data->textures->torch, "   ./assets/torch/torch.xpm");
	set_texture_path(data, &data->textures->torch1, "   ./assets/torch/torch1.xpm");
	set_texture_path(data, &data->textures->torch2, "   ./assets/torch/torch2.xpm");
	set_texture_path(data, &data->textures->torch3, "   ./assets/torch/torch3.xpm");
	set_texture_path(data, &data->textures->torch4, "   ./assets/torch/torch4.xpm");
	set_texture_path(data, &data->textures->torch5, "   ./assets/torch/torch5.xpm");
	set_texture_path(data, &data->textures->door,"   ./assets/door.xpm");
	if (!data->textures->torch1 || !data->textures->torch2
		|| !data->textures->torch3 || !data->textures->torch4
		|| !data->textures->torch5)
		return (0);
	return (1);
}

#include <stdio.h>
void	place_torch(t_data *data)
{
	static int	torch_frame = 0;
	torch_frame++;
	printf("torch_frame: %d\n", torch_frame);
	if (torch_frame > 0 && torch_frame < 25)
		blend_torch_scaled_onto_frame(data->mlx->mainframe_img,
			data->textures->torch, 200, 200);
	if (torch_frame > 25 && torch_frame < 50)
		blend_torch_scaled_onto_frame(data->mlx->mainframe_img,
			data->textures->torch1, 200, 200);
	if (torch_frame > 50 && torch_frame < 75)
		blend_torch_scaled_onto_frame(data->mlx->mainframe_img,
			data->textures->torch2, 200, 200);
	if (torch_frame > 75 && torch_frame < 100)
		blend_torch_scaled_onto_frame(data->mlx->mainframe_img,
			data->textures->torch3, 200, 200);
	if (torch_frame > 100 && torch_frame < 125)
		blend_torch_scaled_onto_frame(data->mlx->mainframe_img,
			data->textures->torch4, 200, 200);
	if (torch_frame > 125 && torch_frame < 150)
		blend_torch_scaled_onto_frame(data->mlx->mainframe_img,
			data->textures->torch5, 200, 200);
	if (torch_frame > 150)
		torch_frame = 0;

}


