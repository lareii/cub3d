/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 01:55:53 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/28 15:13:35 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perp_wall_dist;
}	t_ray;

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
	int		bpp;
	int		size_line;
	int		endian;
}	t_image;

#endif