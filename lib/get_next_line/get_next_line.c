/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:09:56 by ebabaogl          #+#    #+#             */
/*   Updated: 2024/11/04 18:59:10 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static char	*update_buffer(char *buf, int index)
{
	size_t	i;

	i = 0;
	while (buf[index] && buf[index + 1] != '\0')
	{
		buf[i] = buf[index + 1];
		index++;
		i++;
	}
	while (buf[i])
		buf[i++] = '\0';
	return (buf);
}

static char	*get_line(char *buf)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!*buf)
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (!buf[i])
		line[i] = '\0';
	else if (buf[i] == '\n')
		line[i] = '\n';
	buf = update_buffer(buf, i);
	return (line);
}

static char	*read_file(int fd, char *buf)
{
	char	*tmp_str;
	char	*tmp_buf;
	ssize_t	r_bytes;

	tmp_str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp_str)
		return (free(buf), NULL);
	while (1)
	{
		r_bytes = read(fd, tmp_str, BUFFER_SIZE);
		if (r_bytes == -1)
			return (free(tmp_str), NULL);
		if (r_bytes == 0)
			break ;
		tmp_buf = ft_strjoin(buf, tmp_str);
		if (!tmp_buf)
			return (free(tmp_str), free(buf), NULL);
		free(buf);
		buf = tmp_buf;
		ft_memset(tmp_str, 0, BUFFER_SIZE + 1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (free(tmp_str), buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (free(buf), buf = NULL, NULL);
	if (!buf)
	{
		buf = ft_calloc(1, 1);
		if (!buf)
			return (NULL);
	}
	buf = read_file(fd, buf);
	if (!buf)
		return (NULL);
	line = get_line(buf);
	if (!line)
		return (free(buf), buf = NULL, NULL);
	return (line);
}
