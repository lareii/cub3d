/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:09:52 by ebabaogl          #+#    #+#             */
/*   Updated: 2024/11/03 12:24:27 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len--)
		*ptr++ = (unsigned char)c;
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
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

size_t	ft_strlen(char *s)
{
	const char	*c;

	if (!s)
		return (0);
	c = s;
	while (*c)
		c++;
	return (c - s);
}

char	*ft_strchr(char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (*s && *s != uc)
		s++;
	if (*s == uc || !uc)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!str || !s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	return (str);
}
