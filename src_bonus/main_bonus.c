/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 04:03:41 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/29 16:48:18 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <stdlib.h>
#include <unistd.h>

void	free_all(t_data *data)
{
	free_textures(data);
	free_map(data);
	free_player(data);
	destroy_win(data->mlx);
	free(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc_c(1, sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (EXIT_FAILURE);
	}
	if (!init_mlx(data) || !init_map(data, argv) || !init_win(data))
	{
		write(2, "Error\n", 6);
		free_all(data);
		return (EXIT_FAILURE);
	}
	free_all(data);
	return (EXIT_SUCCESS);
}
