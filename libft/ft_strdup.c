/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 12:09:57 by lleiria-          #+#    #+#             */
/*   Updated: 2022/06/03 12:00:40 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include "libft.h"

/*size_t	ft_strlen(const char	*str)
{
	size_t	n;

	n = 0;
	if (!str)
		return (n);
	while (str[n] != '\0')
		n++;
	return (n);
}*/

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	n;
	size_t	slen;

	slen = ft_strlen(s1);
	p = (char *)malloc(sizeof(char) * (slen + 1));
	n = 0;
	if (p == NULL)
		return (NULL);
	while (s1[n] != '\0')
	{
		p[n] = s1[n];
		n++;
	}
	p[n] = '\0';
	return (p);
}

/*int main()
{
    char source[] = "GeeksForGeeks";
 
    // A copy of source is created dynamically
    // and pointer to copy is returned.
    char* target = ft_strdup(source);
 
    printf("%s", target);
    return 0;
}*/