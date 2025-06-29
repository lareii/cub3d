/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 01:55:53 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/30 01:45:47 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_BONUS_H
# define RENDER_BONUS_H

typedef struct s_image
{
	void	*img_ptr;
	char	*data_addr;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;

	// dda
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perp_wall_dist;

	// texture
	t_image	*texture;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	double	tex_step;
	double	tex_pos;
}	t_ray;

typedef struct s_textures
{
	t_image	*north;
	t_image	*south;
	t_image	*west;
	t_image	*east;
	t_image	*door;
	t_image	*torch;
	t_image	*torch1;
	t_image	*torch2;
	t_image	*torch3;
	t_image	*torch4;
	t_image	*torch5;
	int		floor;
	int		ceiling;
}	t_textures;

typedef struct s_circle
{
	int	x;
	int	y;
	int	radius;
	int	color;
}	t_circle;

typedef struct s_rectangle
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rectangle;

void	draw_circle_on_image(t_image *img, t_circle *circle);
void	draw_rectangle_on_image(t_image *img, t_rectangle *rect);

#endif