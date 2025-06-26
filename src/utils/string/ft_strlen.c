/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:37:40 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/26 11:39:14 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen_c(char const *s)
{
	const char	*c;

	if (!s)
		return (0);
	c = s;
	while (*c)
		c++;
	return (c - s);
}
