/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 14:03:14 by jopaning          #+#    #+#             */
/*   Updated: 2020/09/25 11:51:48 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_itoa_counter(int n)
{
	int	counter;

	counter = 1;
	if (n < 0)
		n = -n;
	while (n / 10 > 0)
	{
		counter++;
		n = n / 10;
	}
	return (counter);
}

char		*ft_itoa(int n)
{
	int		length;
	char	*return_s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	length = ft_itoa_counter(n);
	if (n >= 0)
		if (!(return_s = ft_strnew(length)))
			return (NULL);
	if (n < 0)
	{
		if (!(return_s = ft_strnew(++length)))
			return (NULL);
		n = -n;
	}
	while (--length >= 0)
	{
		return_s[length] = n % 10 + '0';
		n = n / 10;
	}
	if (return_s[0] == '0' && return_s[1])
		return_s[0] = '-';
	return (return_s);
}

char		*ft_itoa_base(size_t value, size_t base)
{
	char		*nbr;
	int			i;
	int			neg;
	size_t		tmp;
	char		*bchr;

	tmp = value;
	bchr = "0123456789abcdef";
	i = 1;
	neg = 0;
	while ((tmp /= base) != 0)
		i++;
	nbr = (char*)malloc(sizeof(char) * (i + neg + 1));
	nbr[i + neg] = '\0';
	while (i--)
	{
		nbr[i + neg] = bchr[value % base];
		value = value / base;
	}
	return (nbr);
}
