/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:47:23 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/29 16:55:57 by ebabaogl         ###   ########.fr       */
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

void	free_textures(t_data *data)
{
	if (data->textures && data->textures->north)
	{
		mlx_destroy_image(data->mlx->mlx_ptr, data->textures->north->img_ptr);
		free(data->textures->north);
	}
	if (data->textures && data->textures->south)
	{
		mlx_destroy_image(data->mlx->mlx_ptr, data->textures->south->img_ptr);
		free(data->textures->south);
	}
	if (data->textures && data->textures->west)
	{
		mlx_destroy_image(data->mlx->mlx_ptr, data->textures->west->img_ptr);
		free(data->textures->west);
	}
	if (data->textures && data->textures->east)
	{
		mlx_destroy_image(data->mlx->mlx_ptr, data->textures->east->img_ptr);
		free(data->textures->east);
	}
	if (data->textures)
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
