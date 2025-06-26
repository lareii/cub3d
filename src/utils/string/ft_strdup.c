/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:35:40 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/26 11:36:56 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *s1)
{
	size_t	len;
	size_t	i;
	char	*str;

	len = 0;
	while (s1[len] != '\0')
		len++;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}
