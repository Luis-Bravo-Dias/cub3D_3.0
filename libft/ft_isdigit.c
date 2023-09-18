/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:55:27 by lleiria-          #+#    #+#             */
/*   Updated: 2022/11/25 16:34:43 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
int main()
{
    char c;
    c = '1';
    printf("\nResult when digit: %d", ft_isdigit(c));

    c = '+';
    printf("\nResult when other: %d", ft_isdigit(c));

    c='A';
    printf("\nResult when alphabetic character: %d", ft_isdigit(c));

    return 0;
}
*/
