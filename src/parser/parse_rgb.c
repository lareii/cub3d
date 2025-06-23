/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 23:19:17 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/23 12:57:12 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

static int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

static void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static int	parse_rgb_value(char *str)
{
	int	err;
	int	value;

	err = 0;
	if (str)
	{
		value = ft_atol(str, &err);
		if (err == -1 || value < 0 || value > 255)
			return (-1);
	}
	return (1);
}

int	str_to_rgb(char *str)
{
	char	**rgb_values;
	int		r;
	int		g;
	int		b;

	rgb_values = ft_split(str, ',');
	if (!rgb_values)
		return (0);
	r = parse_rgb_value(rgb_values[0]);
	g = parse_rgb_value(rgb_values[1]);
	b = parse_rgb_value(rgb_values[2]);
	if (r == -1 || g == -1 || b == -1)
	{
		free_array(rgb_values);
		return (0);
	}
	free_array(rgb_values);
	return (rgb_to_int(r, g, b));
}
