/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:21:48 by lleiria-          #+#    #+#             */
/*   Updated: 2021/11/09 13:55:42 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*successor;

	if (!*lst)
		return ;
	while (*lst)
	{
		successor = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = successor;
	}
	*lst = NULL;
}
