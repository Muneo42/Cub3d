/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:02:27 by jopaning          #+#    #+#             */
/*   Updated: 2019/11/04 15:02:49 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1)
	{
		if (((char *)s1)[i] == ((char *)s2)[i])
			i++;
		else
			return (((unsigned char *)s1)[i]
			- ((unsigned char *)s2)[i]);
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
