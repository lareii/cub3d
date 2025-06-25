/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:47:23 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/25 20:44:02 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
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
		free(data->textures->north);
		data->textures->north = NULL;
	}
	if (data->textures && data->textures->south)
	{
		free(data->textures->south);
		data->textures->south = NULL;
	}
	if (data->textures && data->textures->west)
	{
		free(data->textures->west);
		data->textures->west = NULL;
	}
	if (data->textures && data->textures->east)
	{
		free(data->textures->east);
		data->textures->east = NULL;
	}
	if (data->textures)
	{
		free(data->textures);
		data->textures = NULL;
	}
}

void	free_map(t_data *data)
{
	if (data->map && data->map->data)
		free_str_arr(data->map->data);
	if (data->map)
	{
		free(data->map);
		data->map = NULL;
	}
}

void	free_player(t_data *data)
{
	if (data->player)
	{
		free(data->player);
		data->player = NULL;
	}
}
