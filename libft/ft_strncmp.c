/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:23:25 by jopaning          #+#    #+#             */
/*   Updated: 2020/01/07 15:23:27 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int index;

	if (n == 0)
		return (0);
	n--;
	index = 0;
	while (s1[index] == s2[index] && (s1[index] != '\0' || s2[index] != '\0'))
	{
		if (index == n)
			return (0);
		index++;
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
