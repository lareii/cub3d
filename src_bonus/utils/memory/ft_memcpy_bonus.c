/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:40:12 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/29 16:09:06 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	while (n--)
		*d++ = *(unsigned char *)src++;
	return (dst);
}
