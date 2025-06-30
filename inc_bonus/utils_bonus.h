/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:36:06 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/06/29 16:08:25 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include <stddef.h>

// string
char	*ft_strchr_c(char *s, int c);
char	*ft_strdup(char *s1);
char	*ft_strtrim(char *s, char *set);
char	**ft_split(char const *s, char c);
long	ft_atol(const char *str, int *err);
size_t	ft_strlen_c(char const *s);
char	**str_arr_join(char **arr, char *line);
void	free_str_arr(char **arr);

// memory
void	*ft_calloc_c(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif