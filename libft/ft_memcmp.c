/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:05:57 by lleiria-          #+#    #+#             */
/*   Updated: 2021/10/29 12:02:01 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	count = 0;
	while (count < n)
	{
		if (str1[count] != str2[count])
			return (str1[count] - str2[count]);
		count++;
	}
	return (0);
}
/*
int	main(void)
{
	char test1[] = "abcd";
	char test2[] = "abCd";
	char test3[] = "abcd";
	char test4[] = "abce";
	char test5[] = "abcefg";
	char test6[] = "abT";

	printf("%d\n", ft_memcmp(test1, test2, 3));//positivo
	printf("%d\n", ft_memcmp(test1, test3, 3));//zero
	printf("%d\n", ft_memcmp(test1, test4, 3));//zero
	printf("%d\n", ft_memcmp(test1, test5, 4));//negativo
	printf("%d\n", ft_memcmp(test1, test6, 4));//positivo

	printf("\n");

	printf("%d\n", memcmp(test1, test2, 3));//positivo
	printf("%d\n", memcmp(test1, test3, 3));//zero
	printf("%d\n", memcmp(test1, test4, 3));//zero
	printf("%d\n", memcmp(test1, test5, 4));//negativo
	printf("%d\n", memcmp(test1, test6, 4));//positivo
}*/
