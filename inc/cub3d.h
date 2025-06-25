/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:17:24 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/25 20:36:47 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "config.h"
# include "window.h"
# include "render.h"
# include <stddef.h>

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
void	free_textures(t_textures *textures);
int		init_map_textures(t_data *data, int fd);
int		str_to_rgb(char *str);
int		map_validator(t_data *data);

// utils
char	*ft_strchr_c(char *s, int c);
char	*ft_strtrim(char const *s, char const *set);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
void	*ft_calloc_c(size_t count, size_t size);
long	ft_atol(const char *str, int *err);
size_t	ft_strlen_c(char const *s);
void	free_str_arr(char **array);
void	free_map(t_map *map);

size_t	str_arr_len(char **arr);
char	**str_arr_join(char **arr, char *line);

#endif
