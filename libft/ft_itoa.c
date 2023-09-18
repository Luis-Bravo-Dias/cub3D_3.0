/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:16:00 by lleiria-          #+#    #+#             */
/*   Updated: 2021/11/11 11:24:11 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlen(long int i)
{
	int	count;

	count = 0;
	if (i < 0)
	{
		i *= -1;
		count++;
	}
	while (i > 0)
	{
		i /= 10;
		count++;
	}
	return (count);
}

char	*ft_transform(long int nb, char *s, int len)
{
	if (nb < 0)
	{
		s[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		s[len--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char		*s;
	int			len;
	long int	nb;
	char		*s2;

	nb = n;
	if (nb == 0)
	{
		return (ft_strdup("0"));
	}
	len = ft_nlen(nb);
	s = malloc(sizeof(char) * len + 1);
	if (!s)
		return (NULL);
	s[len--] = 0;
	s2 = ft_transform(nb, s, len);
	return (s2);
}
/*
#include <stdio.h>


int main()
{
	printf("%s", ft_itoa(0));
	printf("%d", itoa(0));
}
*/
