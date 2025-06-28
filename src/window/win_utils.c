/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 04:17:09 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/28 12:37:22 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "mlx.h"
#include <stdlib.h>
#include <sys/time.h>

void	destroy_win(t_mlx *mlx)
{
	if (mlx && mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx && mlx->mlx_ptr)
		#if defined(__linux__)
			mlx_destroy_display(mlx->mlx_ptr);
		#else
			exit(1);
		#endif
	if (mlx && mlx->mainframe_img)
		free(mlx->mainframe_img);
	if (mlx && mlx->mlx_ptr)
		free(mlx->mlx_ptr);
	if (mlx && mlx->keys)
		free(mlx->keys);
	if (mlx)
		free(mlx);
}

double	get_time_in_seconds()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return tv.tv_sec + tv.tv_usec / 1000000.0;
}
