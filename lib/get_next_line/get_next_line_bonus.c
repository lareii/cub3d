/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:09:56 by ebabaogl          #+#    #+#             */
/*   Updated: 2024/11/04 10:31:50 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

static char	*update_buffer(char *buf, int index)
{
	size_t	i;

	i = 0;
	if (!buf)
		return (NULL);
	while (buf[index] && buf[index + 1] != '\0')
	{
		buf[i] = buf[index + 1];
		index++;
		i++;
	}
	while (buf[i])
		buf[i++] = 0;
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
		return (free(tmp_str), free(buf), NULL);
	while (1)
	{
		r_bytes = read(fd, tmp_str, BUFFER_SIZE);
		if (r_bytes == -1)
			return (free(tmp_str), NULL);
		if (r_bytes == 0)
			return (free(tmp_str), buf);
		tmp_buf = ft_strjoin(buf, tmp_str);
		if (!tmp_buf)
			return (free(tmp_str), free(buf), NULL);
		free(buf);
		ft_memset(tmp_str, 0, BUFFER_SIZE + 1);
		buf = tmp_buf;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (free(tmp_str), buf);
}

char	*get_next_line(int fd)
{
	static char	*buf[FD_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (free(buf[fd]), buf[fd] = NULL, NULL);
	if (!buf[fd])
	{
		buf[fd] = ft_calloc(1, 1);
		if (!buf[fd])
			return (NULL);
	}
	buf[fd] = read_file(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = get_line(buf[fd]);
	if (!line)
	{
		free(buf[fd]);
		buf[fd] = NULL;
	}
	return (line);
}
