/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:05:06 by lleiria-          #+#    #+#             */
/*   Updated: 2021/11/10 12:09:00 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	n;
	size_t	result;
	size_t	sign;

	n = 0;
	result = 0;
	sign = 1;
	if (!str[0] || !str)
		return (0);
	while ((str[n] >= 9 && str[n] <= 13) || str[n] == 32)
		n++;
	if (str[n] == '-' || str[n] == '+')
		if (str[n++] == '-')
			sign *= -1;
	if (str[n] == '-' || str[n] == '+')
		return (0);
	while (str[n] >= '0' && str[n] <= '9')
	{
		result *= 10;
		result += str[n] - '0';
		n++;
	}
	return (result * sign);
}
/*
int main () {
   int val;
   char str[20];
   
   strcpy(str, "98993489");
   val = atoi(str);
   printf("String value = %s, Int value = %d\n", str, val);

   strcpy(str, "tutorialspoint.com");
   val = atoi(str);
   printf("String value = %s, Int value = %d\n", str, val);

   return(0);
}*/
