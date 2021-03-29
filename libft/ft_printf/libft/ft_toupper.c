/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:39:59 by jopaning          #+#    #+#             */
/*   Updated: 2020/09/25 11:58:24 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

char		*ft_toupper_str(char *str)
{
	char	*s;

	s = str;
	while (*s)
	{
		*s = ft_toupper(*s);
		s++;
	}
	return (str);
}
