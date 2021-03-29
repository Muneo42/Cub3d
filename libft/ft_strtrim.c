/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 19:02:15 by jopaning          #+#    #+#             */
/*   Updated: 2020/01/08 11:01:16 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	size_t	len;
	char	*str;
	int		j;

	i = 0;
	j = ft_strlen(s1);
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (ft_strchr(set, s1[i]) != NULL && i < j)
		i++;
	while (ft_strchr(set, s1[j]) != NULL && j > 0)
		j--;
	if (j == 0)
		return (ft_strnew(0));
	len = j - i + 1;
	if (!(str = ft_substr(s1, i, len)))
		return (NULL);
	str[len] = '\0';
	return (str);
}
