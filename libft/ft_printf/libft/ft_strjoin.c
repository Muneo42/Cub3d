/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:35:35 by jopaning          #+#    #+#             */
/*   Updated: 2020/09/02 15:35:53 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		counter;
	int		i;
	int		i_s1;
	char	*return_s;

	i = 0;
	counter = 0;
	if (!s1 || !s2)
		return (NULL);
	i_s1 = ft_strlen(s1);
	counter = i_s1 + ft_strlen(s2);
	if ((return_s = (char *)malloc(sizeof(return_s) * (counter + 2))) == NULL)
		return (NULL);
	while (i < i_s1)
	{
		return_s[i] = s1[i];
		i++;
	}
	while (i < counter)
	{
		return_s[i] = s2[i - i_s1];
		i++;
	}
	return_s[i] = '\0';
	return (return_s);
}
