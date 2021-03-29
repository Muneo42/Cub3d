/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 16:02:55 by jopaning          #+#    #+#             */
/*   Updated: 2020/09/28 10:55:01 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_precis(t_printf *st_arg, char *d_temp, int d)
{
	void	*pt;
	char	*temp;
	int		len;

	len = ft_strlen(d_temp);
	temp = ft_strnew(st_arg->precision + 1);
	pt = temp;
	if (d < 0 && !(st_arg->c_conversion == 'u' || st_arg->c_conversion == 'x'
		|| st_arg->c_conversion == 'X'))
	{
		*temp++ = '-';
	}
	while (st_arg->precision > len)
	{
		*temp = '0';
		temp++;
		len++;
	}
	while (*d_temp)
	{
		*temp = *d_temp;
		temp++;
		d_temp++;
	}
	return (pt);
}
