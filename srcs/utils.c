/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 22:54:21 by jopaning          #+#    #+#             */
/*   Updated: 2021/03/24 22:54:22 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double			calc_dst_vector(t_vector vector, t_vector actual)
{
	double	dst;

	dst = pow(vector.x - actual.x, 2) + pow(vector.y - actual.y, 2);
	return (dst);
}
