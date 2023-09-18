/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:43:38 by lleiria-          #+#    #+#             */
/*   Updated: 2021/11/08 10:43:38 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*new_end;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new_end = ft_lstlast(*lst);
	new_end->next = new;
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
    
    ft_lstadd_back(&lst1, lst2);
    ft_lstadd_back(&lst1, lst3);

    while (lst1 != NULL)
    {
        printf("%s", lst1->content);
        lst1 = lst1->next;
    }
}*/

/*
int main(void)
{
    t_list **lst;
    t_list *lst_head;
    char **str;
    char a;

    a = 'a';
    int i;

    i = 1000;

    lst = malloc(sizeof (t_list *) * i);
    str = (char **)malloc(sizeof(char *) * i);
    while (i > 0)
    {
        str[i] = ft_strdup(ft_itoa(i));
        i--;
    }
    i = 1000;
    while (i > 0)
    {
        (*lst) = ft_lstnew(str[i--]);
        ft_lstadd_back(lst, (*lst)->next);
        (*lst) = (*lst)->next;
    }
    
    while ((*lst)->next != NULL)
    {
        printf("lst->content: %s\n", (*lst)->content);
        (*lst) = (*lst)->next;
    }
 
}*/