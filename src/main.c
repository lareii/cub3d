/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 04:03:41 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/24 13:53:36 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <unistd.h>

static void	free_all(t_data *data)
{
	free_textures(data->textures);
	free_map(data->map);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (EXIT_FAILURE);
	}
	if (!init_map(&data, argv))
		return (EXIT_FAILURE);
	if (!init_win(&data))
		return (EXIT_FAILURE);
	free_all(&data);
	// free_map
	// free_player ...
	return (EXIT_SUCCESS);
}
