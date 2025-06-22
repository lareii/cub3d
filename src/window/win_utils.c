/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 04:17:09 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/22 04:23:12 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "mlx.h"
#include <stdlib.h>

void	destroy_win(t_mlx *mlx)
{
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
		#if defined(__linux__)
		mlx_destroy_display(mlx->mlx_ptr); // temporary solution
		#endif
	free(mlx->mlx_ptr);
}