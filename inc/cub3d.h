/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:17:24 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/19 02:31:32 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600

# define CIRCLE_COLOR 0xFF0000

typedef struct s_data { // for testing
	void *mlx;
	void *win;
	void *img;
	char *addr;
	int bpp;
	int line_length;
	int endian;
	int x;
	int y;
	int key_w;
	int key_a;
	int key_s;
	int key_d;
} t_data;

void	draw_pixel_on_image(t_data *data, int x, int y, int color);
void	draw_circle_on_image(t_data *data, int radius, int x, int y);

#endif