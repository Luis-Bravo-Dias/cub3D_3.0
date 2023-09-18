/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:20:18 by lleiria-          #+#    #+#             */
/*   Updated: 2023/03/01 12:47:21 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	n1;
	size_t	n2;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s) + 1;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	n1 = 0;
	n2 = 0;
	while (s[n1])
	{
		if (n1 >= start && n2 < len)
		{
			p[n2] = s[n1];
			n2++;
		}
		n1++;
	}
	p[n2] = '\0';
	return (p);
}
/*
#include <stdio.h>

int main()
{
	char *text = "texto_exemplo";
	
	printf("%s \n",ft_substr(text, 3, 6));
}
*/