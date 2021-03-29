/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:16:05 by jopaning          #+#    #+#             */
/*   Updated: 2021/03/28 15:57:28 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int result;
	int positive;

	i = 0;
	result = 0;
	positive = 1;
	while (ft_iswhitespace(str[i]) == 1)
		i++;
	if (str[i] != '-' && str[i] != '+' && ft_isdigit(str[i]) == 0)
		return (0);
	if (str[i] == '-')
		positive = -1;
	if (ft_isdigit(str[i]) == 0)
		i++;
	while (ft_isdigit(str[i]) == 1)
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * positive);
}
