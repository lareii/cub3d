/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:36:52 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/26 11:39:29 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

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
