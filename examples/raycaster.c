/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 02:26:04 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/21 21:56:48 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "mlx.h"
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_mlx;

typedef struct s_player
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		move_speed;
	int		rotate_speed;

	int move_forward;
	int move_backward;
	int strafe_left;
	int strafe_right;
	int turn_left;
	int turn_right;
}	t_player;

typedef	struct	s_data
{
	t_mlx		*mlx;
	t_player	*player;

	int		window_width;
	int		window_height;
	int		map_width;
	int		map_height;
}	t_data;

int			worldMap[24][24] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

void	place_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= 640 || y < 0 || y >= 480)
		return;
	dst = mlx->data_addr + (y * mlx->size_line + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

time_t	get_current_time(void)
{
	struct	timeval	tv;
	
	gettimeofday(&tv, NULL);
	return (tv.tv_usec);
}

void draw(t_data *data)
{
	t_player *player = data->player;

	for (int x = 0; x < data->window_width; x++)
	{
		player->cameraX = 2 * x / (double)(data->window_width) - 1;
		player->rayDirX = player->dirX + player->planeX * player->cameraX; // = cos(θ)
		player->rayDirY = player->dirY + player->planeY * player->cameraX; // = sin(θ)

		int	mapX = (int)(player->posX);
		int	mapY = (int)(player->posY);
		
		double sideDistX;
		double sideDistY;

		// x veya y'de bir birim gidilecegi icin 1 aliniyor. 
		double deltaDistX = (player->rayDirX == 0) ? 1e30 : fabs(1 / player->rayDirX); // bolen 0 olursa diye olmayacak bir sayi veriyoruz
		double deltaDistY = (player->rayDirY == 0) ? 1e30 : fabs(1 / player->rayDirY); // zaten x yetisemezse y yetisecek her turlu

		int stepX;
		int stepY;
		int	side;
		int hit = 0;
		if (player->rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (player->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - player->posX) * deltaDistX;
		}
		if (player->rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (player->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - player->posY) * deltaDistY;
		}

		while (!hit)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (worldMap[mapY][mapX] > 0) //worldMap[mapX][mapY]
				hit = 1;
		}
		
		double perpWallDist;
		if (!side)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);
		
		int lineHeight = (int)(data->window_height / perpWallDist);
		int drawStart = -lineHeight / 2 + data->window_height / 2;
		int drawEnd = lineHeight / 2 + data->window_height / 2;
		if (drawStart < 0)
			drawStart = 0;
		if (drawEnd >= data->window_height)
			drawEnd = data->window_height - 1;
		
		for (int y = drawStart; y <= drawEnd; y++)
			place_pixel(data->mlx, data->window_width - x - 1, y, 0x00FF0000);
	}
}

int keypress_handler(int keycode, t_data *data)
{
	// t_player *p = data->player;
	// double moveSpeed = 5.00;
	// double rotSpeed = 0.05;

	// if (keycode == XK_w)
	// {
	// 	if (worldMap[(int)(p->posY)][(int)(p->posX + p->dirX * moveSpeed)] == 0)
	// 		p->posX += p->dirX * moveSpeed;
	// 	if (worldMap[(int)(p->posY + p->dirY * moveSpeed)][(int)(p->posX)] == 0)
	// 		p->posY += p->dirY * moveSpeed;
	// }
	// if (keycode == XK_s)
	// {
	// 	if (worldMap[(int)(p->posY)][(int)(p->posX - p->dirX * moveSpeed)] == 0)
	// 		p->posX -= p->dirX * moveSpeed;
	// 	if (worldMap[(int)(p->posY - p->dirY * moveSpeed)][(int)(p->posX)] == 0)
	// 		p->posY -= p->dirY * moveSpeed;
	// }
	// if (keycode == XK_d)
	// {
	// 	double perpX = p->dirY;
	// 	double perpY = -p->dirX;
	// 	if (worldMap[(int)(p->posY)][(int)(p->posX + perpX * moveSpeed)] == 0)
	// 		p->posX += perpX * moveSpeed;
	// 	if (worldMap[(int)(p->posY + perpY * moveSpeed)][(int)(p->posX)] == 0)
	// 		p->posY += perpY * moveSpeed;
	// }
	// if (keycode == XK_a)
	// {
	// 	double perpX = -p->dirY;
	// 	double perpY = p->dirX;
	// 	if (worldMap[(int)(p->posY)][(int)(p->posX + perpX * moveSpeed)] == 0)
	// 		p->posX += perpX * moveSpeed;
	// 	if (worldMap[(int)(p->posY + perpY * moveSpeed)][(int)(p->posX)] == 0)
	// 		p->posY += perpY * moveSpeed;
	// }
	// if (keycode == XK_Left || keycode == XK_Right)
	// {
	// 	double oldDirX = p->dirX;
	// 	double oldPlaneX = p->planeX;
	// 	double angle = (keycode == XK_Left) ? -rotSpeed : rotSpeed;

	// 	p->dirX = p->dirX * cos(angle) - p->dirY * sin(angle);
	// 	p->dirY = oldDirX * sin(angle) + p->dirY * cos(angle);
	// 	p->planeX = p->planeX * cos(angle) - p->planeY * sin(angle);
	// 	p->planeY = oldPlaneX * sin(angle) + p->planeY * cos(angle);
	// }
	// return (0);

	t_player *p = data->player;

	if (keycode == XK_w)
		p->move_forward = 1;
	if (keycode == XK_s)
		p->move_backward = 1;
	if (keycode == XK_a)
		p->strafe_left = 1;
	if (keycode == XK_d)
		p->strafe_right = 1;
	if (keycode == XK_Left)
		p->turn_left = 1;
	if (keycode == XK_Right)
		p->turn_right = 1;
	return (0);
}

void handle_movement(t_player *p)
{
	double moveSpeed = 0.1;
	double rotSpeed = 0.05;

	if (p->move_forward)
	{
		if (worldMap[(int)(p->posY)][(int)(p->posX + p->dirX * moveSpeed)] == 0)
			p->posX += p->dirX * moveSpeed;
		if (worldMap[(int)(p->posY + p->dirY * moveSpeed)][(int)(p->posX)] == 0)
			p->posY += p->dirY * moveSpeed;
	}
	if (p->move_backward)
	{
		if (worldMap[(int)(p->posY)][(int)(p->posX - p->dirX * moveSpeed)] == 0)
			p->posX -= p->dirX * moveSpeed;
		if (worldMap[(int)(p->posY - p->dirY * moveSpeed)][(int)(p->posX)] == 0)
			p->posY -= p->dirY * moveSpeed;
	}
	if (p->strafe_right)
	{
		double perpX = p->dirY;
		double perpY = -p->dirX;
		if (worldMap[(int)(p->posY)][(int)(p->posX + perpX * moveSpeed)] == 0)
			p->posX += perpX * moveSpeed;
		if (worldMap[(int)(p->posY + perpY * moveSpeed)][(int)(p->posX)] == 0)
			p->posY += perpY * moveSpeed;
	}
	if (p->strafe_left)
	{
		double perpX = -p->dirY;
		double perpY = p->dirX;
		if (worldMap[(int)(p->posY)][(int)(p->posX + perpX * moveSpeed)] == 0)
			p->posX += perpX * moveSpeed;
		if (worldMap[(int)(p->posY + perpY * moveSpeed)][(int)(p->posX)] == 0)
			p->posY += perpY * moveSpeed;
	}
	if (p->turn_left || p->turn_right)
	{
		double angle = (p->turn_left ? -rotSpeed : rotSpeed);
		double oldDirX = p->dirX;
		double oldPlaneX = p->planeX;
		p->dirX = p->dirX * cos(angle) - p->dirY * sin(angle);
		p->dirY = oldDirX * sin(angle) + p->dirY * cos(angle);
		p->planeX = p->planeX * cos(angle) - p->planeY * sin(angle);
		p->planeY = oldPlaneX * sin(angle) + p->planeY * cos(angle);
	}
}

int	game_loop(t_data *data)
{
	mlx_clear_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
	handle_movement(data->player);
	draw(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr, data->mlx->img_ptr, 0, 0);
	return (0);
}

int	main()
{
	t_data		data;
	t_mlx		mlx;
	t_player	player;

	data.window_width = 640;
	data.window_height = 480;
	data.map_width = 24;
	data.map_height = 24;
	data.mlx = &mlx;
	data.player = &player;

	// init MLX
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, data.window_width, data.window_height, "cub3d");
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, data.window_width, data.window_height);
	mlx.data_addr = mlx_get_data_addr(mlx.img_ptr, &mlx.bits_per_pixel, &mlx.size_line, &mlx.endian);

	// init player
	player.posX = 22;
	player.posY = 12;
	player.dirX = -1;
	player.dirY = 0;
	player.planeX = 0;
	player.planeY = 0.66;

	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, keypress_handler, &data);
	mlx_loop_hook(mlx.mlx_ptr, game_loop, &data);
	mlx_loop(mlx.mlx_ptr);
}