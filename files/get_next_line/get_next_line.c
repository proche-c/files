/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_the_line(char *remaining)
{
	int		i;
	char	*next_line;

	i = 0;
	if (remaining[0] == '\0')
		return (NULL);
	while (remaining[i] != '\n' && remaining[i] != '\0')
		i++;
	next_line = malloc((ft_strlen(remaining) + 1) * sizeof(char));
	if (!next_line)
		return (NULL);
	i = 0;
	while (remaining[i] != '\n' && remaining[i] != '\0')
	{
		next_line[i] = remaining[i];
		i++;
	}
	if (remaining[i] == '\n')
	{
		next_line[i] = remaining[i];
		i++;
	}
	next_line[i] = '\0';
	return (next_line);
}

char	*ft_update_remaining(char *remaining)
{
	char	*rem;
	int		i;
	int		j;

	i = 0;
	while (remaining[i] != '\n' && remaining[i] != '\0')
		i++;
	if (!remaining[i])
	{
		free(remaining);
		return (NULL);
	}
	rem = malloc((ft_strlen(remaining) - i + 1) * sizeof(char));
	if (!rem)
	{
		free(remaining);
		return (NULL);
	}
	i++;
	j = 0;
	while (remaining[i] != '\0')
		rem[j++] = remaining[i++];
	rem[j] = '\0';
	free(remaining);
	return (rem);
}

char	*ft_get_remaining(int fd, char *remaining)
{
	ssize_t	read_bytes;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes > 0)
		{
			buffer[read_bytes] = '\0';
			remaining = ft_join_str(remaining, buffer);
		}
	}
	free (buffer);
	if (read_bytes == -1)
	{
		free(remaining);
		return (NULL);
	}
	return (remaining);
}

char	*get_next_line(int fd)
{
	static char	*remaining;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((remaining && !ft_strchr(remaining, '\n')) || !remaining)
		remaining = ft_get_remaining(fd, remaining);
	if (!remaining)
		return (NULL);
	next_line = ft_get_the_line(remaining);
	if (!next_line)
	{
		free(remaining);
		return (NULL);
	}
	remaining = ft_update_remaining(remaining);
	return (next_line);
}
