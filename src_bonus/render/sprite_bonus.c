/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 01:40:08 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/30 12:05:55 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static unsigned int	get_scaled_pixel_color(t_image *torch,
	int src_x, int src_y)
{
	char	*src_pixel;

	src_pixel = torch->data_addr
		+ (src_y * torch->size_line + src_x * (torch->bpp / 8));
	return (*(unsigned int *)src_pixel);
}

static void	blend_torch_scaled_onto_frame(t_image *frame,
	t_image *torch, int draw_width, int draw_height)
{
	int				y;
	int				x;
	int				dst_x;
	int				dst_y;
	unsigned int	color;

	y = 0;
	while (y < draw_height)
	{
		x = 0;
		while (x < draw_width)
		{
			color = get_scaled_pixel_color(torch,
					(int)((float)torch->width / draw_width * x),
					(int)((float)torch->height / draw_height * y));
			if (color != 0xFF000000)
			{
				dst_x = frame->width - x;
				dst_y = frame->height - draw_height + y + 30;
				draw_pixel_on_image(frame, color, dst_x, dst_y);
			}
			x++;
		}
		y++;
	}
}

int	init_bonus_textures(t_data *data)
{
	set_texture_path(data, &data->textures->torch,
		"   ./assets/torch/torch.xpm");
	set_texture_path(data, &data->textures->torch1,
		"   ./assets/torch/torch1.xpm");
	set_texture_path(data, &data->textures->torch2,
		"   ./assets/torch/torch2.xpm");
	set_texture_path(data, &data->textures->torch3,
		"   ./assets/torch/torch3.xpm");
	set_texture_path(data, &data->textures->torch4,
		"   ./assets/torch/torch4.xpm");
	set_texture_path(data, &data->textures->torch5,
		"   ./assets/torch/torch5.xpm");
	set_texture_path(data, &data->textures->door,
		"   ./assets/door.xpm");
	if (!data->textures->torch1 || !data->textures->torch2
		|| !data->textures->torch3 || !data->textures->torch4
		|| !data->textures->torch5 || !data->textures->door)
		return (0);
	return (1);
}

void	place_torch(t_data *data)
{
	static int	torch_frame = 0;

	torch_frame++;
	if (torch_frame > 0 && torch_frame <= 25)
		blend_torch_scaled_onto_frame(data->mlx->mainframe_img,
			data->textures->torch, 300, 300);
	if (torch_frame > 25 && torch_frame <= 50)
		blend_torch_scaled_onto_frame(data->mlx->mainframe_img,
			data->textures->torch1, 300, 300);
	if (torch_frame > 50 && torch_frame <= 75)
		blend_torch_scaled_onto_frame(data->mlx->mainframe_img,
			data->textures->torch2, 300, 300);
	if (torch_frame > 75 && torch_frame <= 100)
		blend_torch_scaled_onto_frame(data->mlx->mainframe_img,
			data->textures->torch3, 300, 300);
	if (torch_frame > 100 && torch_frame <= 125)
		blend_torch_scaled_onto_frame(data->mlx->mainframe_img,
			data->textures->torch4, 300, 300);
	if (torch_frame > 125 && torch_frame <= 150)
		blend_torch_scaled_onto_frame(data->mlx->mainframe_img,
			data->textures->torch5, 300, 300);
	if (torch_frame > 150)
		torch_frame = 0;
}
