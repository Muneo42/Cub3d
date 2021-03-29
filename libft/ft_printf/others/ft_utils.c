/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 14:27:24 by jopaning          #+#    #+#             */
/*   Updated: 2020/09/03 14:27:44 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	char			*ft_base(unsigned long long number, int base,
int count, char *str)
{
	while (number != 0)
	{
		if ((number % base) < 10)
			str[count - 1] = (number % base) + 48;
		else
			str[count - 1] = (number % base) + 55;
		number /= base;
		count--;
	}
	return (str);
}

char					*ft_utl_base(unsigned long long number, int base)
{
	unsigned long long	temp;
	int					count;
	char				*str;

	temp = number;
	str = 0;
	count = 0;
	if (number == 0)
		return (ft_strdup("0"));
	while (number != 0)
	{
		number /= base;
		count++;
	}
	if (!(str = malloc(count + 1)))
		return (0);
	str[count] = '\0';
	str = ft_base(temp, base, count, str);
	return (str);
}
