/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 23:19:17 by ahekinci          #+#    #+#             */
/*   Updated: 2025/07/04 15:23:24 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <stdlib.h>

static int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

static int	parse_rgb_value(char *str)
{
	int	err;
	int	value;
	int	i;

	err = 0;
	value = 0;
	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == ' ')
			{
				i++;
				continue ;
			}
			if (str[i] < '0' || str[i] > '9')
				return (-1);
			i++;
		}
		value = ft_atol(str, &err);
		if (err == -1 || value < 0 || value > 255)
			return (-1);
	}
	return (value);
}

static int	count_char(const char *str, char c)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

int	str_to_rgb(char *str)
{
	char	**rgb_values;
	int		r;
	int		g;
	int		b;

	rgb_values = ft_split(str, ',');
	if (!str || count_char(str, ',') != 2 || !rgb_values)
	{
		free_str_arr(rgb_values);
		free(str);
		return (-1);
	}
	r = parse_rgb_value(rgb_values[0]);
	g = parse_rgb_value(rgb_values[1]);
	b = parse_rgb_value(rgb_values[2]);
	if (r == -1 || g == -1 || b == -1)
	{
		free_str_arr(rgb_values);
		free(str);
		return (-1);
	}
	free_str_arr(rgb_values);
	free(str);
	return (rgb_to_int(r, g, b));
}
