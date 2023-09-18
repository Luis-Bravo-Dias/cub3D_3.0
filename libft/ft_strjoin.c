/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:58:52 by lleiria-          #+#    #+#             */
/*   Updated: 2021/11/03 17:10:56 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*snew;
	size_t	n1;
	size_t	n2;
	size_t	slen;

	if (!s1 || !s2)
		return (NULL);
	slen = ft_strlen(s1) + ft_strlen(s2);
	snew = (char *)malloc(sizeof(char) * (slen + 1));
	n1 = 0;
	n2 = 0;
	if (snew == NULL)
		return (NULL);
	while (s1[n1] != '\0')
	{
		snew[n1] = s1[n1];
		n1++;
	}
	while (s2[n2] != '\0')
	{
		snew[n1 + n2] = s2[n2];
		n2++;
	}
	snew[n1 + n2] = '\0';
	return (snew);
}
