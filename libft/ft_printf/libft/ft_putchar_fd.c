/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:03:25 by jopaning          #+#    #+#             */
/*   Updated: 2020/09/02 15:14:53 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	int	ret;

	if ((ret = write(fd, &c, 1)) == -1)
		ft_putstr_fd("Error while using write()", 1);
}
