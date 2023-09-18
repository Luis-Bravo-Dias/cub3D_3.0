/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:43:46 by lleiria-          #+#    #+#             */
/*   Updated: 2021/10/28 14:57:44 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
#include "libft.h"

/*void	*ft_bzero(void	*str, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		((unsigned char *)str)[count] = '0';
		count++;
	}
	return (str);
}*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, size * count);
	return (ptr);
}

/*int main(void)
{
    int *p = (int *) ft_calloc(10, sizeof(int));

    //int *p = (int *) malloc(10 * sizeof(int));

    p[0] = 10;
    p[6] = 15;

   int i;
   for (i = 0; i < 10; ++i)
   {
       printf("Endereco de p%i = %p | Valor de p%i = %i\n", i, &p[i], i, *(p+i));
   }

    free (p);

    return 0;
}*/
