/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 20:31:29 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/25 20:17:15 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*ft_strchr_c(char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (*s && *s != uc)
		s++;
	if (*s == uc || !uc)
		return ((char *)s);
	return (NULL);
}

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

char	*ft_strtrim(char *s, char *set)
{
	int		len;
	int		left;
	int		right;
	char	*str;

	if (!s)
		return (NULL);
	left = 0;
	right = ft_strlen_c(s) - 1;
	while (s[left] && ft_strchr_c(set, s[left]))
		left++;
	while (right > left && ft_strchr_c(set, s[right]))
		right--;
	if (left > right)
		return (ft_strdup(""));
	len = right - left + 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s + left, len);
	str[len] = '\0';
	return (str);
}

void	free_str_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

size_t	str_arr_len(char **arr)
{
	size_t	count;

	count = 0;
	while (arr && *arr)
	{
		arr++;
		count++;
	}
	return (count);
}

char	**str_arr_join(char **arr, char *line)
{
	char	**new_arr;
	size_t	size;
	size_t	i;

	i = 0;
	size = str_arr_len(arr);
	new_arr = malloc(sizeof(char *) * (size + 2));
	if (!new_arr)
		return (NULL);
	while (i < size)
	{
		new_arr[i] = arr[i];
		i++;
	}
	new_arr[i] = line;
	new_arr[i + 1] = NULL;
	free(arr);
	return (new_arr);
}

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
