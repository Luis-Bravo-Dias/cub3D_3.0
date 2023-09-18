/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:52:14 by lleiria-          #+#    #+#             */
/*   Updated: 2022/07/27 17:16:27 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr2(const char *s, int c)
{
	char	*tmp;

	if (s)
	{
		tmp = (char *)(s);
		while (*tmp)
		{
			if (*tmp == (char)c)
				return (tmp);
			tmp++;
		}
		if (*tmp == c)
			return (tmp);
	}
	return (NULL);
}

size_t	ft_strlen2(const char	*str)
{
	size_t	n;
	char	*safe;

	n = 0;
	safe = (char *)str;
	while (safe && *safe)
	{
		safe++;
		n++;
	}
	return (n);
}

void	*ft_memcpy2(void	*dest, const void *src, size_t n)
{
	size_t	count;

	if (dest == NULL && src == NULL)
		return (NULL);
	count = 0;
	while (count < n)
	{
		((char *)dest)[count] = ((const char *)src)[count];
		count++;
	}
	return (dest);
}

char	*ft_strdup2(const char *s)
{
	char	*str;
	int		len;

	if (s)
	{
		len = ft_strlen2(s);
		if (!len)
			return (NULL);
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (!str)
			return (NULL);
		ft_memcpy2(str, s, len);
		*(str + len) = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_strjoin2(const char *s1, const char *s2)
{
	size_t	i;
	size_t	s1len;
	size_t	s2len;
	char	*ptr;

	i = 0;
	ptr = NULL;
	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return (ft_strdup2(s1));
	else if (!s1 && s2)
		return (ft_strdup2(s2));
	s1len = ft_strlen2(s1);
	s2len = ft_strlen2(s2);
	ptr = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!ptr)
		return (NULL);
	while (i < (s1len + s2len + 1))
		ptr[i++] = 0;
	ft_memcpy2(ptr, s1, s1len);
	ft_memcpy2(ptr + s1len, s2, s2len);
	ptr[s1len + s2len] = '\0';
	return (ptr);
}
