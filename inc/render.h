/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 01:55:53 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/22 02:38:35 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

typedef struct s_textures
{
	void	*north;
	void	*south;
	void	*west;
	void	*east;
	int		floor;
	int		ceiling;
}	t_textures;

typedef struct s_image
{
	void	*img_ptr;
	char	*data_addr;
	int		width;
	int		height;
	int		bbp;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_circle {
	int	x;
	int	y;
	int	radius;
	int	color;
} t_circle;

typedef struct s_rectangle {
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rectangle;

// for example usage:
// int draw_circle(t_circle circle)
// draw_circle((t_circle){.x = 400, .y = 300, .radius = 50, .color = CIRCLE_COLOR});

// void	draw_pixel_on_image(t_data *data, int x, int y, int color);
// void	draw_circle_on_image(t_data *data, int radius, int x, int y);

#endif