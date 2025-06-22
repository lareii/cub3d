/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 04:03:41 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/22 19:28:52 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	(void)argv;
	if (!init_win(&data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
