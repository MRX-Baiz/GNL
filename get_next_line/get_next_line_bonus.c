/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaiz <mbaiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 08:39:05 by mbaiz             #+#    #+#             */
/*   Updated: 2024/04/12 06:02:54 by mbaiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 0)
		return (NULL);
	stash[fd] = ft_read(stash[fd], fd);
	if (!stash[fd])
		return (NULL);
	line = ft_getline(stash[fd]);
	stash[fd] = remove_first_line(stash[fd]);
	return (line);
}

char	*ft_read(char *str, int fd)
{
	int		i;
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 1;
	while (i > 0 && ft_strchr(str, '\n') == NULL)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			free(str);
			return (str = NULL, buffer = NULL, NULL);
		}
		buffer[i] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
	}
	free(buffer);
	return (str);
}

char	*ft_getline(char *str)
{
	char	*line;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!str || str[i] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*remove_first_line(char *multistr)
{
	int		i;
	int		j;
	char	*restlines;

	i = 0;
	j = 0;
	if (!multistr || *multistr == '\0')
		return (free(multistr), multistr = NULL, NULL);
	while (multistr[i] && multistr[i] != '\n')
		i++;
	if (multistr [i] == '\n')
		i++;
	restlines = (char *)malloc(ft_strlen(multistr) - i + 1);
	if (!restlines)
		return (NULL);
	while (multistr[i])
	{
		restlines[j] = multistr[i];
		j++;
		i++;
	}
	restlines[j] = '\0';
	free(multistr);
	return (multistr = NULL, restlines);
}
