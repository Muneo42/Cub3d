/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 13:40:49 by jopaning          #+#    #+#             */
/*   Updated: 2020/10/01 11:21:19 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		ft_tester(t_printf *st_arg, int d)
{
	int		len;
	char	*tmp;

	tmp = ft_itoa(d);
	len = ft_strlen(tmp);
	free(tmp);
	if (st_arg->flag_minus == 1 || st_arg->flag_zero == 1
	|| st_arg->precision != -1)
	{
		if (len < st_arg->width && st_arg->precision != -1)
			return (0);
		return (1);
	}
	return (0);
}

static void		ft_conv_d_ext(t_printf *st_arg, char *d_temp, int d)
{
	if (st_arg->precision >= 0)
		st_arg->flag_zero = 0;
	if (d < 0 && st_arg->width > (int)ft_strlen(d_temp) && d != -2147483648
		&& st_arg->flag_zero)
	{
		ft_putchar_ct(st_arg, '-');
		d_temp = ft_itoa(-d);
		st_arg->width--;
	}
	ft_conv_s(st_arg, d_temp);
}

void			ft_conv_d(t_printf *st_arg, int d)
{
	char	*temp;
	char	*d_temp;

	if (d < 0 && ft_tester(st_arg, d) && d != -2147483648 && st_arg->width > 0)
	{
		ft_putchar_ct(st_arg, '-');
		d = -d;
		st_arg->width--;
	}
	if (st_arg->precision == 0 && d == 0)
		d_temp = ft_strdup("");
	else
		d_temp = ft_itoa(d);
	if (st_arg->precision < (int)ft_strlen(d_temp))
		ft_conv_d_ext(st_arg, d_temp, d);
	else
	{
		if (*d_temp == '-')
			*d_temp = '0';
		temp = ft_precis(st_arg, d_temp, d);
		st_arg->flag_zero = 0;
		ft_conv_s(st_arg, temp);
		free(temp);
	}
	free(d_temp);
}
