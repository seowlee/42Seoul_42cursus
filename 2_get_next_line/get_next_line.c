/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowlee <seowlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:45:01 by seowlee           #+#    #+#             */
/*   Updated: 2021/02/04 23:49:01 by seowlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	split_line(char **line, char **backup, char *newline)
{
	char	*temp;

	if (newline)
	{
		*newline = '\0';
		*line = ft_strdup(*backup);
		temp = ft_strdup(newline + 1);
		free(*backup);
		*backup = temp;
		return (1);
	}
	if (*backup)
	{
		*line = ft_strdup(*backup);
		free(*backup);
		*backup = NULL;
	}
	else
		*backup = ft_strdup("");
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*backup[OPEN_MAX];
	char		*newline;
	int			byte;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	if (!backup[fd])
		backup[fd] = ft_strdup("");
	while (!(newline = ft_strchr(backup[fd], '\n'))
		&& (byte = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[byte] = '\0';
		newline = ft_strjoin(backup[fd], buf);
		free(backup[fd]);
		backup[fd] = newline;
	}
	free(buf);
	if (byte < 0)
		return (-1);
	return (split_line(line, &backup[fd], newline));
}
