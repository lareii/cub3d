/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 01:55:37 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/22 02:07:50 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600

# define MOVE_SPEED_FACTOR 5.0
# define ROT_SPEED_FACTOR 3.0
# define FOV 66
// double fov_deg = 66.0;
// double fov_rad = fov_deg * M_PI / 180.0;
// double planeY = tan(fov_rad / 2.0); // sonuç ≈ 0.66

# define WALL_COLLISION_PAD 1.0 // ayarla sonra

# define MINIMAP_WIDTH 100
# define MINIMAP_HEIGHT 100
# define MINIMAP_TILE_SIZE 10
# define MINIMAP_PLAYER_COLOR 0xFF0000
# define MINIMAP_PLAYER_RADIUS 2

#endif