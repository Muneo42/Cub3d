/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 22:54:01 by jopaning          #+#    #+#             */
/*   Updated: 2021/03/29 15:27:53 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		init_radar(t_radar *r, t_data *d)
{
	r->vec.y = d->p.vector.y;
	r->vec.x = d->p.vector.x;
	r->t = (double)(-tan(r->alpha));
	r->b = r->vec.y - r->t * r->vec.x;
	r->width = d->mini.img.width;
	r->touch = 0;
}

void		radar_mini(t_data *d)
{
	t_radar		r;

	r.alpha = d->p.alpha + M_PI / 6;
	while (r.alpha > d->p.alpha - M_PI / 6)
	{
		init_radar(&r, d);
		while (d->map.tab_map[(int)r.vec.y][(int)r.vec.x] != '1' && r.width)
		{
			if (r.alpha == M_PI_2)
				r.vec.y = r.vec.y - (sin(r.alpha) / d->mini.size);
			else
			{
				r.vec.x = r.vec.x + (cos(r.alpha) / d->mini.size);
				r.vec.y = r.t * r.vec.x + r.b;
			}
			r.width--;
		}
		r.alpha -= M_PI / 3 / d->r[0];
	}
}

t_vector	next_wall(t_data *d, t_radar *r)
{
	t_vector	hit;

	r->vec_y = calc_next_y(*r);
	r->vec_x = calc_next_x(*r);
	r->touch = compare_vec(d->p.vector, r->vec_y, r->vec_x, &r->vec);
	hit = next_block(r->vec.x, r->vec.y, &d->p.vector);
	if (d->map.tab_map[(int)hit.y][(int)hit.x] == '2')
		init_sprite(d, '2', hit, r);
	return (hit);
}

void		radar(t_data *d)
{
	t_radar		r;
	t_vector	hit;
	void		*tab_s[10];
	int			i;

	i = 0;
	r.alpha = d->p.alpha + M_PI / 6;
	while (r.alpha > d->p.alpha - M_PI / 6)
	//while (i < d->r[0])
	{
		//r.alpha = ((d->r[0] / i) * (M_PI / 3)) - (d->p.alpha + M_PI / 6);
		init_radar(&r, d);
		ft_bzero(tab_s, sizeof(void *));
		hit = next_block(r.vec.x, r.vec.y, &d->p.vector);
		while (d->map.tab_map[(int)hit.y][(int)hit.x] != '1')
			hit = next_wall(d, &r);
		r.dist = sqrt(calc_dst_vector(d->p.vector, r.vec));
		display_wall(d, &r, i);
		if (d->tab_s[0].dist != 0)
			display_sprite(d, i);
		i++;
		r.alpha -= M_PI / 3 / (double)d->r[0];
	}
	if (!d->save)
		if ((mlx_put_image_to_window(d->ptr, d->win, d->img.image, 0, 0)) == -1)
			ft_error("Error\nIMage couldn't be display", d, 4);
}
