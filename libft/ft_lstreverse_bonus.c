/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:41:53 by jopaning          #+#    #+#             */
/*   Updated: 2020/01/08 19:42:42 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lstreverse(t_list **alst)
{
	t_list	*new;
	t_list	*old;
	t_list	*temp;

	old = *alst;
	new = NULL;
	while (old)
	{
		temp = old;
		old = temp->next;
		temp->next = new;
		new = temp;
	}
	*alst = new;
}
