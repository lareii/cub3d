/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arr_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:42:43 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/29 16:09:12 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	str_arr_len(char **arr)
{
	size_t	count;

	count = 0;
	while (arr && *arr)
	{
		arr++;
		count++;
	}
	return (count);
}

void	free_str_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**str_arr_join(char **arr, char *line)
{
	char	**new_arr;
	size_t	size;
	size_t	i;

	i = 0;
	size = str_arr_len(arr);
	new_arr = malloc(sizeof(char *) * (size + 2));
	if (!new_arr)
		return (NULL);
	while (i < size)
	{
		new_arr[i] = arr[i];
		i++;
	}
	new_arr[i] = line;
	new_arr[i + 1] = NULL;
	free(arr);
	return (new_arr);
}
