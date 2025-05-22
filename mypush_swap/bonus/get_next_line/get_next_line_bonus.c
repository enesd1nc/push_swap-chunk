/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:26:07 by mdinc             #+#    #+#             */
/*   Updated: 2025/05/22 22:23:40 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

static char	*ft_new_rest(char *rest)
{
	char	*new_line;
	int		i;
	int		j;

	i = ft_count_newline(rest);
	if (!rest[i] && rest)
	{
		free(rest);
		return (NULL);
	}
	new_line = malloc(ft_strlen_gnl(rest) - i + 1);
	if (!new_line)
	{
		free(rest);
		return (NULL);
	}
	i++;
	j = 0;
	while (rest[i])
		new_line[j++] = rest[i++];
	new_line[j] = '\0';
	free(rest);
	return (new_line);
}

static char	*ft_red_line(char *rest)
{
	char	*line;
	int		j;

	j = 0;
	if (!rest[j])
		return (NULL);
	if (ft_strchr(rest, '\n'))
		line = malloc(ft_count_newline(rest) + 2);
	else
		line = malloc(ft_count_newline(rest) + 1);
	if (!line)
		return (free(rest), NULL);
	j = -1;
	while (rest[++j] != '\n' && rest[j] != '\0')
		line[j] = rest[j];
	if (rest[j] == '\n')
	{
		line[j] = rest[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*ft_get_rest(int fd, char *rest)
{
	int		read_len;
	char	*temp;

	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
	{
		free(rest);
		return (NULL);
	}
	read_len = 1;
	while (read_len != 0 && !ft_where_newline(rest))
	{
		read_len = read(fd, temp, BUFFER_SIZE);
		if (read_len == -1)
		{
			free(rest);
			free(temp);
			return (NULL);
		}
		temp[read_len] = '\0';
		rest = ft_strjoin_gnl(rest, temp);
	}
	free(temp);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(rest[fd]);
		return (NULL);
	}
	rest[fd] = ft_get_rest(fd, rest[fd]);
	if (!rest[fd])
		return (NULL);
	line = ft_red_line(rest[fd]);
	rest[fd] = ft_new_rest(rest[fd]);
	return (line);
}
