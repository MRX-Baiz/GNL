/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaiz <mbaiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 05:24:27 by mbaiz             #+#    #+#             */
/*   Updated: 2024/04/12 05:39:26 by mbaiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	size_t	n;
	size_t	k;

	n = 0;
	k = ft_strlen(s1);
	tmp = (char *)malloc(k + 1);
	if (!tmp)
		return (NULL);
	while (n < k)
	{
		tmp[n] = s1[n];
		n++;
	}
	tmp[n] = '\0';
	return (tmp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str_return;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	i = 0;
	j = 0;
	str_return = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str_return)
		return (free(s1), s1 = NULL, NULL);
	while (s1[i])
		str_return[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str_return[j++] = s2[i++];
	str_return[j] = '\0';
	free(s1);
	return (s1 = NULL, str_return);
}

char	*ft_strchr(const char *s, int C)
{
	char	c;
	int		i;

	if (!s)
		return (NULL);
	c = (char)C;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
