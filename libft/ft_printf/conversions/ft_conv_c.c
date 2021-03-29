/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 13:40:09 by jopaning          #+#    #+#             */
/*   Updated: 2020/09/24 13:13:22 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_conv_c(t_printf *st_arg, char c)
{
	if (st_arg->flag_minus == 1)
		ft_putchar_ct(st_arg, c);
	while (--st_arg->width > 0)
		ft_putchar_ct(st_arg, ' ');
	if (st_arg->flag_minus == 0)
		ft_putchar_ct(st_arg, c);
}
