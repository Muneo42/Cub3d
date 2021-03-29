/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:17:57 by jopaning          #+#    #+#             */
/*   Updated: 2020/01/07 14:49:43 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *temp;

	if (lst != NULL && del != NULL)
	{
		while (*lst != NULL)
		{
			(*del)((*lst)->content);
			temp = (*lst)->next;
			free(*lst);
			*lst = temp;
		}
		*lst = NULL;
	}
}
