/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 01:55:37 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/25 21:59:19 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# define WINDOW_TITLE "kupucde"
# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600

# define MOVE_SPEED_FACTOR 5.0
# define ROT_SPEED_FACTOR 3.0
# define FOV 66
// double fov_deg = 66.0;
// double fov_rad = fov_deg * M_PI / 180.0;
// double plane_y = tan(fov_rad / 2.0); // sonuç ≈ 0.66

# define WALL_COLLISION_PAD 1.0 // ayarla sonra

# define MINIMAP_WIDTH 100
# define MINIMAP_HEIGHT 100
# define MINIMAP_TILE_SIZE 10
# define MINIMAP_PLAYER_COLOR 0xFF0000
# define MINIMAP_PLAYER_RADIUS 2

#endif