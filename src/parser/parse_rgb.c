/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 23:19:17 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/24 12:25:31 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

static int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
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
		free_str_arr(rgb_values);
		return (0);
	}
	free_str_arr(rgb_values);
	return (rgb_to_int(r, g, b));
}
