/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 13:41:05 by jopaning          #+#    #+#             */
/*   Updated: 2020/09/03 14:02:44 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*precis_p(int len, int size)
{
	int		i;
	char	*return_s;

	i = 2;
	return_s = ft_strnew(len + 2);
	return_s[0] = '0';
	return_s[1] = 'x';
	while (i <= len - size + 1)
	{
		return_s[i] = '0';
		i++;
	}
	return (return_s);
}

void		ft_conv_p(t_printf *st_arg, unsigned long long p)
{
	int		i;
	char	*return_s;
	char	*temp;
	char	*temp2;

	i = 0;
	if (!p && st_arg->precision == 0)
		return_s = ft_strdup("");
	else
		return_s = ft_itoa_base(p, 16);
	while (return_s[i++] != '\0')
		return_s[i] = ft_tolower(return_s[i]);
	if (st_arg->precision > 0)
	{
		temp2 = precis_p(st_arg->precision, ft_strlen(return_s));
		temp = ft_strjoin(temp2, return_s);
		free(temp2);
	}
	else
		temp = ft_strjoin("0x", return_s);
	free(return_s);
	ft_conv_s(st_arg, temp);
	free(temp);
}
