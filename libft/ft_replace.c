/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 23:25:00 by jopaning          #+#    #+#             */
/*   Updated: 2021/03/29 15:45:12 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_replace(char *str, char out, char in)
{
	int		i;
	char	*ptr;

	if (!(ptr = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == out)
		{
			if ((i != (int)ft_strlen(str) - 1 && str[i + 1] == '0') || (i != 0 && str[i - 1] == '0'))
				ptr[i] = str[i];
			else
				ptr[i] = in;
		}
		else
			ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
