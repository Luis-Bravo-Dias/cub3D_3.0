/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:56:38 by lleiria-          #+#    #+#             */
/*   Updated: 2021/11/11 16:01:50 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

/*int main(void)
{
    t_list  *lst1;
    t_list  *lst2;
    t_list  *lst3;

    char *str1;
    char *str2;
    char *str3;

    str1 = ft_strdup("Hello\n");
    str2 = ft_strdup("World\n");
    str3 = ft_strdup("Luiz\n");
    
    lst1 = ft_lstnew(str1);
    lst2 = ft_lstnew(str2);
    lst3 = ft_lstnew(str3);
    
    ft_lstadd_front(&lst1, lst3);
    ft_lstadd_front(&lst1, lst2);

    while (lst1 != NULL)
    {
        printf("%s", lst1->content);
        lst1 = lst1->next;
    }
}*/