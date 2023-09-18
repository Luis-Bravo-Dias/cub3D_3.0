/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:46:19 by lleiria-          #+#    #+#             */
/*   Updated: 2021/11/12 15:39:55 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
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

	printf("%d\n", ft_strncmp(test1, test2, 3));//positivo
	printf("%d\n", ft_strncmp(test1, test3, 3));//zero
	printf("%d\n", ft_strncmp(test1, test4, 3));//zero
	printf("%d\n", ft_strncmp(test1, test5, 4));//negativo
	printf("%d\n", ft_strncmp(test1, test6, 4));//positivo
	
	printf("\n");

	printf("%d\n", strncmp(test1, test2, 3));//positivo
	printf("%d\n", strncmp(test1, test3, 3));//zero
	printf("%d\n", strncmp(test1, test4, 3));//zero
	printf("%d\n", strncmp(test1, test5, 4));//negativo
	printf("%d\n", strncmp(test1, test6, 4));//positivo
}*/