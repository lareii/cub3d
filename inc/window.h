/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 01:57:34 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/22 02:29:44 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# if defined(__APPLE__) && defined(__MACH__)
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_ESC 53
# elif defined(__linux__)
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_ESC 65307
# endif

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

typedef struct s_keys
{
	int	key_w;
	int	key_a;
	int	key_s;
	int	key_d;
}	t_keys;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	*mainframe_img;
	t_image	*minimap_img;
	t_keys	*keys;
}	t_mlx;

#endif