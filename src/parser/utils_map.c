/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:47:23 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/25 22:11:57 by ahekinci         ###   ########.fr       */
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

void	free_textures(t_textures *textures)
{
	if (textures && textures->north)
		free(textures->north);
	if (textures && textures->south)
		free(textures->south);
	if (textures && textures->west)
		free(textures->west);
	if (textures && textures->east)
		free(textures->east);
	if (textures)
		free(textures);
}

void	free_map(t_map *map)
{
	if (map && map->data)
		free_str_arr(map->data);
	if (map)
		free(map);
}

void	free_player(t_player *player)
{
	if (player)
		free(player);
}
