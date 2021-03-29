/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 22:54:15 by jopaning          #+#    #+#             */
/*   Updated: 2021/03/29 16:08:30 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		init_sprite(t_data *d, char type, t_vector hit, t_radar *r)
{
	t_sprite	sprite;
	int			i;

	i = 0;
	sprite.vec.x = hit.x;
	sprite.vec.y = hit.y;
	sprite.vec_mid.x = (int)hit.x + 0.5;
	sprite.vec_mid.y = (int)hit.y + 0.5;
	sprite.pos[1].x = cosf(d->p.alpha - M_PI / 2) / 2 + sprite.vec_mid.x;
	sprite.pos[1].y = sinf(d->p.alpha - M_PI / 2) / 2 + sprite.vec_mid.y;
	sprite.pos[0].x = cosf(d->p.alpha + M_PI / 2) / 2 + sprite.vec_mid.x;
	sprite.pos[0].y = sinf(d->p.alpha + M_PI / 2) / 2 + sprite.vec_mid.y;
	//sprite.dist = hypotf(sprite.vec_mid.x - d->p.vector.x, sprite.vec_mid.y - d->p.vector.y);
	sprite.dist = sqrt(calc_dst_vector(sprite.vec_mid, d->p.vector));
	sprite.type = type;
	sprite.next = 0;
	sprite.alpha = r->alpha;
	if (sprite.alpha >= (M_PI * 2))
		sprite.alpha -= M_PI * 2;
	if (sprite.alpha < 0)
		sprite.alpha += M_PI * 2;
	sprite.touch = r->touch;
	while (d->tab_s[i].dist != 0)
		i++;
	d->tab_s[i] = sprite;
}

void		display_sprite(t_data *d, int i)
{
	int		k;
	int		y;
	double	j;
	int		color;
	double	dist;

	k = 0;
	while (d->tab_s[k].dist != 0)
		k++;
	while (--k >= 0)
	{

		j = -1;
		dist = (double)(d->r[1] / d->tab_s[k].dist);
		y = ((d->r[1] - dist) / 2);
		while (dist-- > 0)
		{
			color = color_sprite(d, y, i, d->tab_s[k]);
			//color = 1;
			if (color > 0x000000 && color < 0xFFFFFF)
				image_set_pixel(&d->img, i, y, color);
			y++;
		}
		d->tab_s[k].dist = 0;
	}
}

int        between(t_vector inter, t_vector c, t_vector d)
{
	return ((((inter.x >= c.x && inter.x <= d.x)
	|| (inter.x >= d.x && inter.x <= c.x))
	&& ((inter.y >= c.y && inter.y <= d.y)
	|| (inter.y >= d.y && inter.y <= c.y))));
}

int			color_sprite(t_data *d, double y, int x, t_sprite sprite)
{
	int		color;
	t_vector	temp;
//	float	inter;
	double	dist = (double)(d->r[1] / sprite.dist);

	(void)d;
	(void)y;
	(void)x;
	(void)sprite;
	y = y - ((d->r[1] - dist) / 2);
	t_vector	temp2;
	temp2.x = d->p.vector.x + cos(sprite.alpha);
	temp2.y = d->p.vector.y + sin(sprite.alpha);
	temp = intersect(d->p.vector, temp2, sprite.pos[0], sprite.pos[1]);
	if (!between(temp, sprite.pos[1], sprite.pos[0]))
		return (0);
	//printf("%f %f\n", temp.x, temp.y);
	//color = sqrt(calc_dst_vector(sprite.pos[0], temp));
	color = image_get_pixel(&d->texture.sp,
	(int)((d->texture.sp.width) * sqrt(calc_dst_vector(temp, sprite.pos[1]))),
	(int)(((y / (d->r[1] - dist)) * d->texture.sp.height)));
	//color = image_get_pixel(&d->texture.sp, temp2.x * d->texture.sp.width, y / (d->r[1] / sprite.dist) * d->texture.sp.height);
/*	if (sprite.alpha <= M_PI_2)
		inter = (sprite.touch == 0 ? cos(sprite.alpha) +
		diffx * sin(sprite.alpha) : diffy * cos(sprite.alpha));
	else if (sprite.alpha > M_PI_2 && sprite.alpha <= M_PI)
		inter = (sprite.touch == 0 ? sin(sprite.alpha) * diffx :
		sin(sprite.alpha) - (1 - diffy) * cos(sprite.alpha));
	else if (sprite.alpha > M_PI && sprite.alpha <= 3 * M_PI_2)
		inter = (sprite.touch == 0 ? 1 + sin(sprite.alpha) * diffx :
		1 + (sin(sprite.alpha) + diffy * cos(sprite.alpha)));
	else
		inter = (sprite.touch == 0 ? sin(sprite.alpha) * (diffx - 1) :
		-sin(sprite.alpha) + diffy * cos(sprite.alpha));
	color = image_get_pixel(&d->texture.sp, inter * d->texture.sp.width,
	pixel / (d->r[1] / sprite.dist) * d->texture.sp.height);*/
	return (color);
}
