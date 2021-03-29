/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:50:12 by jopaning          #+#    #+#             */
/*   Updated: 2020/09/03 14:15:23 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_printer(t_printf *st_arg, va_list args)
{
	if (st_arg->c_conversion == '%')
		ft_conv_s(st_arg, "%");
	else if (st_arg->c_conversion == 'c')
		ft_conv_c(st_arg, va_arg(args, int));
	else if (st_arg->c_conversion == 's')
		ft_conv_s(st_arg, va_arg(args, char*));
	else if (st_arg->c_conversion == 'p')
		ft_conv_p(st_arg, va_arg(args, unsigned long long));
	else if (st_arg->c_conversion == 'd' || st_arg->c_conversion == 'i')
		ft_conv_d(st_arg, va_arg(args, int));
	else if (st_arg->c_conversion == 'u')
		ft_conv_u(st_arg, va_arg(args, unsigned int));
	else if (st_arg->c_conversion == 'x' || st_arg->c_conversion == 'X')
		ft_conv_x(st_arg, va_arg(args, unsigned int));
	else
		st_arg->st_counter = -1;
	args++;
}
