#include "mlx.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 600
#define RED 0xFF0000
#define GREEN 0x00FF00
#define LINE_COLOR 0xFFFFFF
#define SPEED 5

typedef struct s_point {
	int x;
	int y;
} t_point;

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	t_point	red;
	t_point	green;
	struct timespec	last_frame;
	double	fps;
} t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		char *dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_circle(t_data *data, int x0, int y0, int r, int color)
{
	for (int y = -r; y <= r; y++)
	{
		for (int x = -r; x <= r; x++)
		{
			if (x * x + y * y <= r * r)
				my_mlx_pixel_put(data, x0 + x, y0 + y, color);
		}
	}
}

void	draw_line(t_data *data, int x1, int y1, int x2, int y2, int color)
{
	float dx = x2 - x1;
	float dy = y2 - y1;
	int steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
	float x_inc = dx / steps;
	float y_inc = dy / steps;
	float x = x1;
	float y = y1;

	for (int i = 0; i <= steps; i++)
	{
		my_mlx_pixel_put(data, (int)x, (int)y, color);
		x += x_inc;
		y += y_inc;
	}
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 13) // W
		data->red.y -= SPEED;
	if (keycode == 1) // S
		data->red.y += SPEED;
	if (keycode == 0) // A
		data->red.x -= SPEED;
	if (keycode == 2) // D
		data->red.x += SPEED;
	if (keycode == 53) // ESC
		exit(0);
	return (0);
}

int	mouse_hook(int x, int y, t_data *data)
{
	data->green.x = x;
	data->green.y = y;
	return (0);
}

void	update_fps(t_data *data)
{
	struct timespec now;
	clock_gettime(CLOCK_MONOTONIC, &now);

	double elapsed = (now.tv_sec - data->last_frame.tv_sec)
					+ (now.tv_nsec - data->last_frame.tv_nsec) / 1e9;

	data->fps = 1.0 / elapsed;
	data->last_frame = now;
}

int	render(t_data *data)
{
	char fps_str[64];

	update_fps(data);

	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len, &data->endian);

	draw_line(data, data->red.x, data->red.y, data->green.x, data->green.y, LINE_COLOR);
	draw_circle(data, data->red.x, data->red.y, 5, RED);
	draw_circle(data, data->green.x, data->green.y, 5, GREEN);

	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);

	// FPS yazdır
	snprintf(fps_str, sizeof(fps_str), "FPS: %.1f", data->fps);
	mlx_string_put(data->mlx, data->win, WIDTH - 100, 20, 0xFFFFFF, fps_str);

	return (0);
}

int	main(void)
{
	t_data data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "FPS - WASD & Mouse");
	data.red.x = WIDTH / 4;
	data.red.y = HEIGHT / 2;
	data.green.x = WIDTH / 2;
	data.green.y = HEIGHT / 2;
	clock_gettime(CLOCK_MONOTONIC, &data.last_frame);
	data.fps = 0;

	mlx_hook(data.win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.win, 6, 1L << 6, mouse_hook, &data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (0);
}
