/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:27:36 by lleiria-          #+#    #+#             */
/*   Updated: 2021/11/10 12:20:02 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_bzero(void	*str, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		((unsigned char *)str)[count] = 0;
		count++;
	}
	return (str);
}
/*
int main () 
{
   char str[50];

   strcpy(str,"This is string.h library function");
   puts(str);

ft_bzero(str, 7);
   puts(str);

   return(0);
}*/
