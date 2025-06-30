/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:47:23 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/30 01:54:48 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "mlx.h"
#include <stddef.h>
#include <stdlib.h>

int	filename_checker(char *str)
{
	size_t	i;

	if (ft_strlen_c(str) < 5)
		return (0);
	else
	{
		i = ft_strlen_c(str) - 1;
		if (!(str[i] == 'b' && str[i - 1] == 'u'
				&& str[i - 2] == 'c' && str[i - 3] == '.'))
			return (0);
		if (str[i - 4] == '/' || str[i - 4] == '\0')
			return (0);
	}
	return (1);
}

static void	destroy_texture(t_data *data, t_image **texture)
{
	if (*texture)
	{
		mlx_destroy_image(data->mlx->mlx_ptr, (*texture)->img_ptr);
		free(*texture);
	}
}

void	free_textures(t_data *data)
{
	if (!data->textures)
		return ;
	destroy_texture(data, &data->textures->north);
	destroy_texture(data, &data->textures->south);
	destroy_texture(data, &data->textures->west);
	destroy_texture(data, &data->textures->east);
	destroy_texture(data, &data->textures->door);
	destroy_texture(data, &data->textures->torch);
	destroy_texture(data, &data->textures->torch1);
	destroy_texture(data, &data->textures->torch2);
	destroy_texture(data, &data->textures->torch3);
	destroy_texture(data, &data->textures->torch4);
	destroy_texture(data, &data->textures->torch5);
	free(data->textures);
}

void	free_map(t_data *data)
{
	if (data->map && data->map->data)
		free_str_arr(data->map->data);
	if (data->map)
		free(data->map);
}

void	free_player(t_data *data)
{
	if (data->player)
		free(data->player);
}
