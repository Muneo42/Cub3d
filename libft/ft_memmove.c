/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:56:33 by jopaning          #+#    #+#             */
/*   Updated: 2020/01/07 10:16:28 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (NULL);
	if (!len)
		return (dst);
	if (src <= dst)
		while (len--)
			((unsigned char *)dst)[len] = ((unsigned char *)
			src)[len];
	else
		ft_memcpy(dst, src, len);
	return ((void *)dst);
}
