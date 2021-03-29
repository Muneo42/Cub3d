/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:35:01 by jopaning          #+#    #+#             */
/*   Updated: 2020/09/02 15:35:12 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*return_char;

	i = 0;
	if (((return_char = (char *)malloc(sizeof(char) * size + 1)) == NULL))
		return (NULL);
	while (i < size + 1)
	{
		return_char[i] = '\0';
		i++;
	}
	return (return_char);
}
