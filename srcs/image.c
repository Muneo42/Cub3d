/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 22:53:47 by jopaning          #+#    #+#             */
/*   Updated: 2021/03/24 22:53:48 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_image		new_image(t_data *d, int w, int h)
{
	t_image	img;

	if ((img.image = mlx_new_image(d->ptr, w, h)) == NULL)
		del_image(d, img);
	img.buffer = (int *)mlx_get_data_addr(img.image, &img.bpp, &img.size_l,
			&img.endian);
	img.bpp /= 8;
	img.width = w;
	img.height = h;
	return (img);
}

void		del_image(t_data *d, t_image img)
{
	if (img.image != NULL)
		mlx_destroy_image(d->ptr, img.image);
}

void		image_set_pixel(t_image *image, int x, int y, int color)
{
	if (!(x < 0 || y < 0 || x >= image->width || y >= image->height))
		*(image->buffer + (x + y * image->width)) = color;
}

int			image_get_pixel(t_image *image, int x, int y)
{
	if (!(x < 0 || y < 0 || x >= image->width || y >= image->height))
		return (image->buffer[x + y * image->width]);
		//return (*(image->buffer + (x + y * image->width)));
	return (0);
}
