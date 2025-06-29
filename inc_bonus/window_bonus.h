/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 01:57:34 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/30 00:12:20 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_BONUS_H
# define WINDOW_BONUS_H

# include "render_bonus.h"

# if defined(__APPLE__) && defined(__MACH__)
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_ESC 53
# elif defined(__linux__)
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_ESC 65307
# endif

typedef struct s_keys
{
	int	key_w;
	int	key_a;
	int	key_s;
	int	key_d;
	int	key_left;
	int	key_right;

	int	mouse_delta_x;
}	t_keys;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	*mainframe_img;
	t_image	*minimap_img;
	t_keys	*keys;
	double	time;
	double	oldtime;
	double	frame_time;
}	t_mlx;

#endif