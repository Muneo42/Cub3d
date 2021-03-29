/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 13:35:51 by jopaning          #+#    #+#             */
/*   Updated: 2020/10/01 11:11:14 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_conv_verif(t_printf *st_arg, char *d_temp)
{
	if (st_arg->precision >= 0)
		st_arg->flag_zero = 0;
	ft_conv_s(st_arg, d_temp);
}

void	ft_conv_u(t_printf *st_arg, unsigned int u)
{
	char	*temp;
	char	*d_temp;

	d_temp = ft_itoa_base((unsigned int)u, 10);
	if (st_arg->precision == 0 && !(ft_strcmp("0", d_temp)))
		ft_conv_s(st_arg, "");
	else
	{
		if (st_arg->precision < (int)ft_strlen(d_temp))
			ft_conv_verif(st_arg, d_temp);
		else
		{
			if (u < 0)
			{
				free(d_temp);
				d_temp = ft_itoa_base(-u, 10);
				u = -u;
			}
			temp = ft_precis(st_arg, d_temp, u);
			st_arg->flag_zero = 0;
			ft_conv_s(st_arg, temp);
			free(temp);
		}
	}
	free(d_temp);
}
