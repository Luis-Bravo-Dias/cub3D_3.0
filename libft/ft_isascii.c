/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:46:24 by lleiria-          #+#    #+#             */
/*   Updated: 2021/10/27 16:13:32 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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
    printf("\nResult when random ASCII: %d", ft_isdigit(c));

    c='A';
    printf("\nResult when alphabetic character: %d", ft_isdigit(c));

    return 0;
}*/
