/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 23:19:17 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:53 by ahekinci         ###   ########.fr       */
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
	int i;

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
				continue;
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

#include <stdio.h>
int	str_to_rgb(char *str)
{
	char	**rgb_values;
	int		r;
	int		g;
	int		b;

	if (!str)
		return (-1);
	if (count_char(str, ',') != 2)
		return (-1);
	rgb_values = ft_split(str, ',');
	if (!rgb_values)
	{
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
	printf("r: %d g: %d b: %d\n", r, g, b);
	return (rgb_to_int(r, g, b));
}
