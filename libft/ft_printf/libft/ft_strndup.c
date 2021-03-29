/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:30:52 by jopaning          #+#    #+#             */
/*   Updated: 2020/09/24 13:25:42 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	len;
	size_t	i;
	char	*result;

	len = ft_strlen(s1);
	if (n > len)
		n = len;
	if ((result = ft_strnew(n)))
	{
		i = 0;
		while (i < n)
		{
			result[i] = s1[i];
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}
