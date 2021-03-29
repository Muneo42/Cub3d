/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:18:35 by jopaning          #+#    #+#             */
/*   Updated: 2020/09/03 14:15:44 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putchar_ct(t_printf *st_arg, char c)
{
	ft_putchar_fd(c, 1);
	st_arg->st_counter++;
}

void	ft_putstr_ct(t_printf *st_arg, char *str)
{
	int	i;

	i = 0;
	if (st_arg->c_conversion == 's' && st_arg->precision != -1)
	{
		while (str[i] && i < st_arg->precision)
		{
			ft_putchar_ct(st_arg, str[i]);
			i++;
		}
	}
	else
	{
		while (str[i])
		{
			ft_putchar_ct(st_arg, str[i]);
			i++;
		}
	}
}
