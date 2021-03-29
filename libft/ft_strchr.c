/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:13:15 by jopaning          #+#    #+#             */
/*   Updated: 2019/11/04 15:13:23 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *p, int c)
{
	char	*temp;

	temp = (char *)p;
	while (*temp)
	{
		if (*temp == c)
			return (temp);
		temp++;
	}
	if (*temp == '\0' && c == '\0')
		return (temp);
	return (0);
}
