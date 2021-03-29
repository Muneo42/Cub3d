/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:25:09 by jopaning          #+#    #+#             */
/*   Updated: 2020/01/07 15:25:19 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cwords(char const *s, char c)
{
	int i;
	int nbwords;
	int inword;

	i = 0;
	nbwords = 0;
	inword = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			inword = 0;
		else if (inword == 0)
		{
			inword = 1;
			nbwords++;
		}
		i++;
	}
	return (nbwords);
}

static int	ft_nchars(char const *s, char c, int i)
{
	int nchars;

	nchars = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		nchars++;
	}
	return (nchars);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_cwords(s, c) + 1))))
		return (NULL);
	while (i < ft_cwords(s, c))
	{
		k = 0;
		while (s[j] == c)
			j++;
		if (!(tab[i] = (char *)malloc(sizeof(char) * (ft_nchars(s, c, j) + 1))))
			return (NULL);
		while (s[j] != c && s[j] != '\0')
			tab[i][k++] = s[j++];
		tab[i][k] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}
