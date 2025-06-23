/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:17:24 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/23 12:30:48 by ebabaogl         ###   ########.fr       */
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
void	init_hooks(t_data *data);
void	destroy_win(t_mlx *mlx);

// parser
int		init_map_data(t_data *data, char **argv);
int		filename_checker(char *str);
void	free_textures(t_textures *textures);
int		init_map_textures(t_data *data, int fd);
int		str_to_rgb(char *str);

// utils
char	*ft_strchr_c(char *s, int c);
char	*ft_strtrim(char const *s, char const *set);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
long	ft_atol(const char *str, int *err);
size_t	ft_strlen_c(char const *s);

#endif
