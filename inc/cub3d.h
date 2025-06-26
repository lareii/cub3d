/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:17:24 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/26 14:27:24 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "config.h"
# include "window.h"
# include "render.h"
# include "utils.h"
# include <stddef.h>

# define PI 3.14159265358979323846

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

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_map
{
	char	**data;
	size_t	width;
	size_t	height;
	char	dir;
}	t_map;

typedef struct s_data
{
	t_mlx		*mlx;
	t_player	*player;
	t_map		*map;
	t_textures	*textures;
}	t_data;

void	free_all(t_data *data);

// window
int		init_win(t_data *data);
void	init_hooks(t_data *data);
void	destroy_win(t_mlx *mlx);

// parser
int		init_map_data(t_map *map, int fd);
int		init_map(t_data *data, char **argv);
int		init_player(t_data *data, size_t x, size_t y);
int		filename_checker(char *str);
void	free_textures(t_data *data);
void	free_map(t_data *data);
void	free_player(t_data *data);
int		init_map_textures(t_data *data, int fd);
int		str_to_rgb(char *str);
int		map_validator(t_data *data);

// render
int		game_loop(t_data *data);
void	draw_pixel_on_image(t_image *img, int color, int x, int y);
void	draw_circle_on_image(t_image *img, t_circle *circle);
void	draw_rectangle_on_image(t_image *img, t_rectangle *rect);
void	raycaster(t_data *data);


#endif
