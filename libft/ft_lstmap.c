/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:36:34 by jopaning          #+#    #+#             */
/*   Updated: 2020/01/02 13:36:44 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*alst;
	t_list	*temp;
	t_list	*first;

	(void)del;
	if (lst == NULL || f == NULL)
		return (NULL);
	temp = (*f)(lst);
	alst = ft_lstnew(temp->content);
	if (alst == NULL)
		return (NULL);
	first = alst;
	lst = lst->next;
	while (lst != NULL)
	{
		temp = (*f)(lst);
		alst->next = ft_lstnew(temp->content);
		if (alst == NULL)
			return (NULL);
		alst = alst->next;
		lst = lst->next;
	}
	return (first);
}
