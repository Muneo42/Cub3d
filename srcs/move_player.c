/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 22:53:54 by jopaning          #+#    #+#             */
/*   Updated: 2021/03/29 14:52:19 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		move_fb(t_data *d, int i)
{
	t_vector	vec;

	vec.x = d->p.vector.x;
	vec.y = d->p.vector.y;
	vec.x += cos(d->p.alpha) * i * d->p.vitesse;
	vec.y -= sin(d->p.alpha) * i * d->p.vitesse;
	if ((int)vec.y > 0 && (int)vec.x > 0 &&
	(int)vec.y < d->map.y_max - 1 && (int)vec.x < d->map.x_max - 1
	&& (d->map.tab_map[(int)vec.y][(int)vec.x] == '1' ||
	d->map.tab_map[(int)vec.y][(int)vec.x] == '0' ||
	d->map.tab_map[(int)vec.y][(int)vec.x] == '2'))
	{
		d->p.vector.x = vec.x;
		d->p.vector.y = vec.y;
	}
}

void		move_lr(t_data *d, int i)
{
	t_vector	vec;

	vec.x = d->p.vector.x;
	vec.y = d->p.vector.y;
	vec.x += cos(d->p.alpha + M_PI_2) * i * d->p.vitesse;
	vec.y -= sin(d->p.alpha + M_PI_2) * i * d->p.vitesse;
	if ((int)vec.y > 0 && (int)vec.x > 0 &&
	(int)vec.y < d->map.y_max - 1 && (int)vec.x < d->map.x_max - 1
	&& (d->map.tab_map[(int)vec.y][(int)vec.x] == '1' ||
	d->map.tab_map[(int)vec.y][(int)vec.x] == '0' ||
	d->map.tab_map[(int)vec.y][(int)vec.x] == '2'))
	{
		d->p.vector.x = vec.x;
		d->p.vector.y = vec.y;
	}
}
