/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:39:46 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/29 16:09:06 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc_c(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size * count)
		ptr[i++] = 0;
	return (ptr);
}
