/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:17:24 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/29 16:08:15 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "config.h"
# include "window.h"
# include "render.h"
# include "utils.h"
# include <stddef.h>

# define PI 3.14159265358979323846

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
double	get_time_in_seconds(void);
int		init_mlx(t_data *data);

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
void	init_texture_render_data(t_data *data, t_ray *ray);
void	select_wall_texture(t_data *data, t_ray *ray);
void	compute_texture_coords(t_ray *ray);
void	draw_texture_line(t_image *img, t_ray *ray, int x, int y);
void	draw_vertical_line(t_data *data, t_ray *ray, size_t x);
void	raycaster(t_data *data);
void	perform_dda(t_ray *ray, char **map, t_player *player, int x);
void	handle_movement(t_data *data);
void	handle_rotation(t_data *data);
void	draw_floor_and_ceiling(t_data *data);

#endif
