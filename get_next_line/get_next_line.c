/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:50:50 by lleiria-          #+#    #+#             */
/*   Updated: 2022/07/27 17:40:10 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*valid_buffer(char **storage, char **buffer, size_t buflen)
{
	char	*returner;
	char	*tmp;
	size_t	storlen;

	storlen = ft_strlen2(*storage);
	returner = (char *)malloc(sizeof(char) * buflen + storlen + 1);
	if (!returner)
		return (0);
	ft_memcpy2(returner, *storage, storlen);
	ft_memcpy2(returner + storlen, *buffer, buflen);
	returner[storlen + buflen] = '\0';
	tmp = ft_strdup2((*buffer) + buflen);
	if (*storage)
		free(*storage);
	(*storage) = tmp;
	return (returner);
}

static char	*feed_storage(char **storage, char **buffer, size_t valid)
{
	char	*tmp;
	char	*returner;

	returner = NULL;
	if (valid <= 0)
	{
		if (valid == 0 && *storage)
		{
			returner = (*storage);
			*storage = NULL;
		}
		return (returner);
	}
	(*buffer)[valid] = '\0';
	tmp = ft_strchr2(*buffer, '\n');
	if (tmp)
		returner = valid_buffer(storage, buffer, (tmp - *buffer) + 1);
	else
	{
		tmp = ft_strjoin2(*storage, *buffer);
		if (*storage)
			free(*storage);
		*storage = tmp;
	}
	return (returner);
}

static char	*valid_storage(char **storage, size_t size)
{
	char	*tmp;
	char	*returner;
	size_t	n;

	returner = malloc(sizeof(char) * (size + 1));
	if (!returner)
		return (0);
	n = -1;
	while (++n != size)
		returner[n] = (*storage)[n];
	returner[n] = '\0';
	tmp = ft_strdup2(*storage + n);
	free (*storage);
	(*storage) = tmp;
	return (returner);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*buffer;
	char		*returner;
	size_t		valid;

	if ((read(fd, NULL, 0) == -1) || (fd < 0 || fd > 1024) || BUFFER_SIZE <= 0)
		return (0);
	valid = 1;
	returner = NULL;
	buffer = ft_strchr2(storage, '\n');
	if (!buffer)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (0);
		while (returner == NULL && valid > 0)
		{
			valid = read(fd, buffer, BUFFER_SIZE);
			returner = feed_storage(&storage, &buffer, valid);
		}
		free (buffer);
		return (returner);
	}
	returner = valid_storage(&storage, (buffer - storage) + 1);
	return (returner);
}
