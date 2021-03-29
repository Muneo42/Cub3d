/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 14:07:33 by jopaning          #+#    #+#             */
/*   Updated: 2020/09/30 14:31:45 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		ft_pass(t_printf *st_arg, char c)
{
	if (st_arg->width < -1)
		st_arg->flag_zero = 0;
	if (st_arg->width < 0 && (st_arg->precision > 0
		|| st_arg->flag_star_p == 0))
	{
		st_arg->flag_minus = 1;
		st_arg->width = -st_arg->width;
	}
	if (c == '*' || c == '.' || c == '-' || c == ' ')
		return (1);
	return (0);
}

static int		ft_counter_adder(const char **format)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strdup(*format);
	while (temp[i] != 'c' && temp[i] != 's' && temp[i] != 'p'
			&& temp[i] != 'd' && temp[i] != 'i' && temp[i] != 'u'
			&& temp[i] != 'x' && temp[i] != 'X' && temp[i] != '%'
			&& temp[i] != '\0')
		i++;
	ft_strdel(&temp);
	return (i + 1);
}

static t_printf	*ft_struct_maker(const char *format)
{
	t_printf	*st_arg;

	st_arg = malloc(sizeof(t_printf));
	st_arg->flag_minus = 0;
	st_arg->flag_zero = 0;
	st_arg->flag_dot = 0;
	st_arg->flag_star_w = 0;
	st_arg->flag_star_p = 0;
	st_arg->width = -1;
	st_arg->precision = -1;
	st_arg->c_conversion = '\0';
	st_arg->arg_counter = ft_counter_adder(&format);
	st_arg->format_cp = ft_strndup(format, st_arg->arg_counter);
	st_arg->st_counter = 0;
	st_arg->cp_pointer = st_arg->format_cp;
	return (st_arg);
}

static void		ft_flag_tester(t_printf *st_arg)
{
	int	i;

	i = 0;
	while (st_arg->format_cp[i])
	{
		if (st_arg->format_cp[i] == '-')
			st_arg->flag_minus = 1;
		else if (st_arg->format_cp[i] == '0' && i == 0)
			st_arg->flag_zero = 1;
		else if (st_arg->format_cp[i] == '.')
			st_arg->flag_dot = 1;
		else if (st_arg->format_cp[i] == '*' && st_arg->format_cp[i - 1] != '.')
			st_arg->flag_star_w = 1;
		else if (st_arg->format_cp[i] == '*' && st_arg->format_cp[i - 1] == '.')
			st_arg->flag_star_p = 1;
		i++;
	}
	if (st_arg->flag_dot == 1 || st_arg->flag_minus == 1)
	{
		if (st_arg->flag_zero == 1 && st_arg->precision <= -1)
			st_arg->flag_zero = 2;
		else
			st_arg->flag_zero = 0;
	}
}

void			printf_arg(const char **format, va_list args, int *counter)
{
	t_printf	*st_arg;

	st_arg = ft_struct_maker(*format + 1);
	ft_flag_tester(st_arg);
	while (*(st_arg->format_cp) == '-' || *(st_arg->format_cp) == '0')
		st_arg->format_cp++;
	if (st_arg->flag_star_w == 1)
		st_arg->width = va_arg(args, int);
	else
		st_arg->width = ft_atoi(st_arg->format_cp);
	if (st_arg->flag_star_p == 1)
		st_arg->precision = va_arg(args, int);
	while (ft_isdigit(*(st_arg->format_cp)) || *(st_arg->format_cp) == '*')
		st_arg->format_cp++;
	if (*(st_arg->format_cp) == '.' && st_arg->flag_star_p == 0)
		st_arg->precision = ft_atoi(++st_arg->format_cp);
	while (ft_pass(st_arg, *(st_arg->format_cp))
			|| ft_isdigit(*st_arg->format_cp))
		st_arg->format_cp++;
	st_arg->c_conversion = *(st_arg->format_cp);
	ft_printer(st_arg, args);
	*format = *format + st_arg->arg_counter + 1;
	*counter = *counter + st_arg->st_counter;
	free(st_arg->cp_pointer);
	free(st_arg);
}
