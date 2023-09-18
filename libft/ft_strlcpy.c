/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:28:54 by lleiria-          #+#    #+#             */
/*   Updated: 2023/03/09 11:19:27 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	n;
	size_t	src_len;

	n = 0;
	src_len = ft_strlen(src);
	if (size != 0)
	{
		while (src[n] != '\0' && n < size - 1)
		{
			dest[n] = src[n];
			n++;
		}
		dest[n] = '\0';
	}
	return (src_len);
}
/*
int main(void)
{
		char text1[] = "12345";
		char text2[] = "abcde";
		printf("%lu\n", strlcpy(text1, text2, 5));
		printf("%s\n", text1);
		char text3[] = "12345";
		char text4[] = "abcde";
		printf("%lu\n", ft_strlcpy(text3, text4, 5));
		printf("%s\n", text3);
}*/