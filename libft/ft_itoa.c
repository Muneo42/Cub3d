/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:22:09 by jopaning          #+#    #+#             */
/*   Updated: 2020/01/08 10:26:02 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbsize(long nb)
{
	int		size;

	size = 1;
	if (nb <= -1)
	{
		nb = nb * (-1);
		size++;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	int				i;
	int				x;
	char			*tab;
	unsigned	int	nb;

	nb = n;
	x = 0;
	i = ft_nbsize((long)n);
	if ((tab = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	tab[i] = '\0';
	if (n < 0)
	{
		x = 1;
		tab[0] = '-';
		nb = n * (-1);
	}
	while (i != x)
	{
		i--;
		tab[i] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (tab);
}
