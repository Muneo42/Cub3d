/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:33:03 by jopaning          #+#    #+#             */
/*   Updated: 2020/09/02 15:33:13 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strdup(const char *str)
{
	char	*temp;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	if (!(temp = (char *)malloc(sizeof(*temp) * (len + 1))))
		return (NULL);
	while (str[i])
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
