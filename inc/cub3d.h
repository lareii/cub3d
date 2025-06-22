/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:17:24 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/22 05:45:32 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "config.h"
# include "window.h"
# include "render.h"

# define PI 3.14159265358979323846

typedef struct s_player
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	rayDirX; // fonksiyon icine at duruma gore
	double	rayDirY;
}	t_player;

typedef struct s_map
{
	char	**data;
	int		width;
	int		height;
	char	dir;
}	t_map;

typedef struct s_data
{
	t_mlx		*mlx;
	t_player	*player;
	t_map		*map;
	t_textures	*textures;
}	t_data;

// window
int		init_win(t_data *data);
void	destroy_win(t_mlx *mlx);
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);
int		destroy_handler(t_mlx *mlx);

// draw
void	draw_pixel_on_image(t_image *img, int color, int x, int y);
void	draw_circle_on_image(t_image *img, t_circle *circle);
void	draw_rectangle_on_image(t_image *img, t_rectangle *rect);
void	draw_map_on_image(t_data *data);
void draw_text(t_data *data);

// render 
int game_loop(t_data *data);
void render(t_data *data);
void	init_player(t_data *data);

// temp initmap
void copy_map_to_struct(int height, int width, char src[height][width], t_map *dest);
void find_player_position(t_map *map, t_player *player);
#endif
