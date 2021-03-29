/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 13:40:33 by jopaning          #+#    #+#             */
/*   Updated: 2020/10/01 11:11:55 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_strlen_custom(t_printf *st_arg, char *s)
{
	if (st_arg->width < 0)
	{
		st_arg->width = -st_arg->width;
		st_arg->flag_minus = 1;
	}
	if (st_arg->c_conversion == 's' && st_arg->precision != -1
	&& st_arg->precision < (int)ft_strlen(s))
		return (ft_strlen(s) - (ft_strlen(s) - st_arg->precision));
	else
		return (ft_strlen(s));
}

void		ft_conv_s(t_printf *st_arg, char *s)
{
	int	len;

	if (st_arg->precision < -1)
		st_arg->precision = -1;
	if (st_arg->c_conversion == 'X' && s)
		s = ft_toupper_str(s);
	if (!s)
		ft_conv_s(st_arg, "(null)");
	else
	{
		len = ft_strlen_custom(st_arg, s);
		if (st_arg->flag_minus == 1)
			ft_putstr_ct(st_arg, s);
		while (len++ < st_arg->width)
		{
			if (st_arg->flag_zero >= 1 && st_arg->flag_minus == 0
				&& st_arg->precision)
				ft_putchar_ct(st_arg, '0');
			else
				ft_putchar_ct(st_arg, ' ');
		}
		if (st_arg->flag_minus == 0)
			ft_putstr_ct(st_arg, s);
	}
}
