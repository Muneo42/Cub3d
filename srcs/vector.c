/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 22:54:30 by jopaning          #+#    #+#             */
/*   Updated: 2021/03/24 22:54:31 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			compare_vec(t_vector start, t_vector end1,
		t_vector end2, t_vector *recep)
{
	if (calc_dst_vector(start, end1) < calc_dst_vector(start, end2))
	{
		recep->x = end1.x;
		recep->y = end1.y;
		return (0);
	}
	else
	{
		recep->x = end2.x;
		recep->y = end2.y;
		return (1);
	}
}

t_vector	next_block(double rx, double ry, t_vector *p)
{
	t_vector	hit;

	hit.x = rx - (p->x > rx && rx == (int)rx ? 0.0001 : 0);
	hit.y = ry - (p->y > ry && ry == (int)ry ? 0.0001 : 0);
	return (hit);
}

t_vector	calc_next_y(t_radar r)
{
	t_vector	vec_y;

	vec_y.x = r.vec.x;
	vec_y.y = r.vec.y;
	if (sin(r.alpha) < 0)
		vec_y.y = ((int)vec_y.y) + 1;
	else
		vec_y.y = (int)vec_y.y + (vec_y.y == (int)vec_y.y ? -1 : 0);
	vec_y.x = (vec_y.y - r.b) / r.t;
	return (vec_y);
}

t_vector	calc_next_x(t_radar r)
{
	t_vector	vec_x;

	vec_x.x = r.vec.x;
	vec_x.y = r.vec.y;
	if (cos(r.alpha) > 0)
		vec_x.x = ((int)vec_x.x + 1);
	else
		vec_x.x = (int)vec_x.x + (vec_x.x == (int)vec_x.x ? -1 : 0);
	vec_x.y = r.t * vec_x.x + r.b;
	return (vec_x);
}

t_vector        intersect(t_vector b, t_vector a, t_vector c, t_vector d)
{
    double		denom;
    t_vector	inter;

    denom = (a.x - b.x) * (c.y - d.y) - (a.y - b.y) *
    (c.x - d.x);
    inter.x = ((a.x * b.y - a.y * b.x) * (c.x - d.x) -
    (a.x - b.x) * (c.x * d.y - c.y * d.x)) / denom;
    inter.y = ((a.x * b.y - a.y * b.x) * (c.y - d.y) -
    (a.y - b.y) * (c.x * d.y - c.y * d.x)) / denom;
    return (inter);
}