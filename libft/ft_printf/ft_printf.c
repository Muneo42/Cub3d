/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:48:23 by jopaning          #+#    #+#             */
/*   Updated: 2020/09/24 13:26:26 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		counter;

	counter = 0;
	va_start(args, str);
	while (*str && counter >= 0)
	{
		if (*str == '%')
			printf_arg(&str, args, &counter);
		else
		{
			ft_putchar_fd(*str, 1);
			counter++;
			str++;
		}
	}
	va_end(args);
	return (counter);
}
