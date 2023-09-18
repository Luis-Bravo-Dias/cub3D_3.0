/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:40:31 by lleiria-          #+#    #+#             */
/*   Updated: 2021/10/29 10:00:28 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_memcpy(void	*dest, const void *src, size_t n)
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
/*
int main ()
{
  char str1[] = "GeGeGe";
  char str2[] = "Quiz";

  printf("str1 before memcpy ");
  puts(str1);

  ft_memcpy(str1, str2, sizeof(str2));

  printf("\nstr1 after memcpy ");
  puts(str1);

  return 0;
}*/
