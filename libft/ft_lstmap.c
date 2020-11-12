/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowlee <seowlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:22:09 by seowlee           #+#    #+#             */
/*   Updated: 2020/11/12 11:37:25 by seowlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *newlist;
	t_list *temp;

	if (lst == NULL || f == NULL)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (temp == NULL)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, temp);
		temp = temp->next;
		lst = lst->next;
	}
	return (newlist);
}
