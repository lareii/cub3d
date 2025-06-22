#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/time.h>

#define WIDTH 800
#define HEIGHT 600
#define RADIUS 10
#define MOVE_SPEED 5

//keys mac
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_ESC 53
#define KEY_W 13

//keys linux
// #define KEY_W 119
// #define KEY_A 97
// #define KEY_S 115
// #define KEY_D 100
// #define KEY_ESC 65307

static double last_time = 0;
static double fps = 0;

typedef struct {
	void *mlx;
	void *win;
	void *img;
	char *addr;
	int bpp;
	int line_length;
	int endian;
	int x;
	int y;
	bool key_w;
	bool key_a;
	bool key_s;
	bool key_d;
} t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return;
	char *dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}


void draw_circle(t_data *data)
{
	int i, j;
	for (i = -RADIUS; i <= RADIUS; i++)
	{
		for (j = -RADIUS; j <= RADIUS; j++)
		{
			if (i*i + j*j <= RADIUS*RADIUS)
				my_mlx_pixel_put(data, data->x + i, data->y + j, 0xFF0000);
		}
	}
}

double get_time_in_seconds()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec + tv.tv_usec / 1000000.0;
}


void draw_text(t_data *data)
{
	char str[50];
	snprintf(str, sizeof(str), "X: %d  Y: %d", data->x, data->y);
	mlx_string_put(data->mlx, data->win, WIDTH - 200, 20, 0xFFFFFF, str);
}

void render(t_data *data)
{
	double current_time = get_time_in_seconds();

	if (last_time != 0)
	{
		double delta = current_time - last_time;
		fps = 1.0 / delta;
	}
	last_time = current_time;

	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_length, &data->endian);
	draw_circle(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	draw_text(data);
	mlx_destroy_image(data->mlx, data->img);

	char fps_str[50];
	snprintf(fps_str, sizeof(fps_str), "FPS: %.1f", fps);
	mlx_string_put(data->mlx, data->win, 20, 20, 0x00FF00, fps_str);
}

int key_press(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->key_w = true;
	if (keycode == KEY_A)
		data->key_a = true;
	if (keycode == KEY_S)
		data->key_s = true;
	if (keycode == KEY_D)
		data->key_d = true;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return 0;
}

int key_release(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->key_w = false;
	if (keycode == KEY_A)
		data->key_a = false;
	if (keycode == KEY_S)
		data->key_s = false;
	if (keycode == KEY_D)
		data->key_d = false;
	return 0;
}

int game_loop(t_data *data)
{
	if (data->key_w)
		data->y -= MOVE_SPEED;
	if (data->key_s)
		data->y += MOVE_SPEED;
	if (data->key_a)
		data->x -= MOVE_SPEED;
	if (data->key_d)
		data->x += MOVE_SPEED;

	render(data);
	return 0;
}

int main()
{
	t_data data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Kirmizi Daire");

	data.x = WIDTH / 2;
	data.y = HEIGHT / 2;
	data.key_w = false;
	data.key_a = false;
	data.key_s = false;
	data.key_d = false;

	render(&data);

	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_loop_hook(data.mlx, game_loop, &data);

	mlx_loop(data.mlx);
	return 0;
}