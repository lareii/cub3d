/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:17:24 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/19 17:04:03 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600

# define MOVE_SPEED 5

# define COLOR 0xFF0000

typedef struct s_image {
	void *img;
	char *addr;
	int width;
	int height;
	int bpp;
	int line_length;
	int endian;
} t_image;

typedef struct s_key_status {
	int key_w;
	int key_a;
	int key_s;
	int key_d;
} t_key_status;

typedef struct s_data {
	void *mlx;
	void *win;
	t_image img;
	int x;
	int y;
	t_key_status key_status;
} t_data;

typedef struct s_circle {
	int x;
	int y;
	int radius;
	int color;
} t_circle;

typedef struct s_rectangle {
	int x;
	int y;
	int width;
	int height;
	int color;
} t_rectangle;


// for example usage:
// int draw_circle(t_circle circle)
// draw_circle((t_circle){.x = 400, .y = 300, .radius = 50, .color = CIRCLE_COLOR});


void	draw_pixel_on_image(t_image *img, int color, int x, int y);
void	draw_circle_on_image(t_image *img, t_circle *circle);
void	draw_rectangle_on_image(t_image *img, t_rectangle *rect);

#endif
