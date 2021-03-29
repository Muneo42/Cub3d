/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 13:39:47 by jopaning          #+#    #+#             */
/*   Updated: 2020/10/01 11:09:35 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_conv_x(t_printf *st_arg, unsigned int x)
{
	char	*temp;
	char	*d_temp;

	d_temp = ft_itoa_base(x, 16);
	if (st_arg->precision == 0 && !(ft_strcmp("0", d_temp)))
		ft_conv_s(st_arg, "");
	else
	{
		if (st_arg->precision < (int)ft_strlen(d_temp))
			ft_conv_verif(st_arg, d_temp);
		else
		{
			if (x < 0)
			{
				free(d_temp);
				d_temp = ft_itoa_base(x, 16);
			}
			temp = ft_precis(st_arg, d_temp, x);
			st_arg->flag_zero = 0;
			ft_conv_s(st_arg, temp);
			free(temp);
		}
	}
	free(d_temp);
}
