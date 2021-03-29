/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:45:44 by jopaning          #+#    #+#             */
/*   Updated: 2020/09/24 13:21:58 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_atoi_tester(int i, const char *str)
{
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int				i;
	unsigned int	final;

	i = 0;
	final = 0;
	i = ft_atoi_tester(i, str);
	if (str[i] == '-')
	{
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		final = final * 10 + str[i] - '0';
		i++;
	}
	return (final);
}
