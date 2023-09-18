/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:38:10 by lleiria-          #+#    #+#             */
/*   Updated: 2021/11/05 14:16:26 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	n;
	char			*snew;
	size_t			slen;

	if (!s || !f)
		return (NULL);
	slen = ft_strlen(s);
	snew = (char *)malloc(sizeof(char) * (slen + 1));
	if (!snew)
		return (0);
	n = 0;
	if (s == NULL)
		return (NULL);
	while (s[n] != '\0')
	{
		snew[n] = f(n, s[n]);
		n++;
	}
	snew[n] = '\0';
	return (snew);
}
