/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:59:56 by lleiria-          #+#    #+#             */
/*   Updated: 2021/10/28 10:18:38 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char	*dest, const char	*src, unsigned int size)
{
	size_t	n;
	size_t	lendest;
	size_t	lensrc;

	n = 0;
	lendest = ft_strlen(dest);
	lensrc = ft_strlen(src);
	if (size == 0)
		return (lensrc);
	while ((src[n] != '\0') && ((lendest + n) < (size - 1)))
	{
		dest[lendest + n] = src[n];
		n++;
	}
	dest[lendest + n] = '\0';
	if (size > lendest)
		return (lendest + lensrc);
	return (size + lensrc);
}
/*
int main(void)
{
	char src[10] = "ab";
	char dest[10] = "123";
	
	printf("Str: %lu\n", strlcat(dest, src, 3));
	printf("Str: %lu", ft_strlcat(dest, src, 3));
	return (0);
}*/