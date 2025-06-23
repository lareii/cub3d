/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:55:23 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/23 12:55:47 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	counter(char const *s, char c)
{
	int	i;
	int	spaces;

	i = 0;
	spaces = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			spaces++;
		i++;
	}
	return (spaces);
}

static void	*free_all(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
	return (NULL);
}

static char	*new_str(char const *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		j;

	j = 0;
	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (counter(s, c) + 1));
	if (!arr)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			arr[j] = new_str(s, c);
			if (!arr[j])
				return (free_all(arr, j));
			j++;
		}
		while (*s && *s != c)
			s++;
	}
	arr[j] = NULL;
	return (arr);
}
