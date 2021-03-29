/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 22:54:59 by jopaning          #+#    #+#             */
/*   Updated: 2021/03/29 16:01:13 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			fill_int(int bit, char *str, t_data *d, short *bit_texture)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	mlx_get_screen_size(d->ptr, &x, &y);
	while (i++ < 1)
	{
		while (*str == ' ')
			str++;
		if (ft_isdigit(*str) && !d->r[i])
			d->r[i] = ft_atoi(str);
		else
			ft_error("ERROR\nResolution", d, 0);
		while (ft_isdigit(*str))
			str++;
	}
	d->r[0] = d->r[0] <= x ? d->r[0] : x;
	d->r[1] = d->r[1] <= y ? d->r[1] : y;
	*bit_texture = *bit_texture | (1 << bit);
	return (i);
}

int			fill_int_rgb(int bit, char *str,
		unsigned int *rgb, t_data *d)
{
	int		tab[3];
	int		i;

	i = -1;
	while (i++ < 2)
	{
		while (*str == ' ')
			str++;
		if (ft_atoi(str) <= 255 && ft_atoi(str) >= 0 && !*rgb)
			tab[i] = ft_atoi(str);
		else
			ft_error(ERROR_COLOR, d, 0);
		while (ft_isdigit(*str) || *str == ' ')
			str++;
		if (*str == ',')
			str++;
	}
	tab[0] = (int)pow(256, 2) * tab[0];
	tab[1] = 256 * tab[1];
	*rgb = tab[0] + tab[1] + tab[2];
	d->texture.bit_texture = d->texture.bit_texture | (1 << bit);
	return (i);
}

void		fill_str(int bit, char *str, t_data *d, t_image *img)
{
	int		i;
	char	*temp;
	int		fd;

	i = 0;
	while (str[i] == ' ')
		i++;
	temp = str + i + 2;
	if (ft_strcmp(temp + ft_strlen(temp) - 4, ".xpm"))
		ft_error("Error\nTexture is not an .xpm\n", d, 0);
	if ((fd = open(temp, O_RDONLY)) == -1)
		ft_error("Error\nTexture couldn't be find\n", d, 0);
	close(fd);
	if ((img->image = mlx_xpm_file_to_image(d->ptr, temp,
					&img->width, &img->height)) == NULL)
		ft_error("Error\nTexture to image didn't work\n", d, 0);
//	free(temp);
	img->buffer = (int *)mlx_get_data_addr(img->image, &img->bpp,
			&img->size_l, &img->endian);
	d->texture.bit_texture = d->texture.bit_texture | (1 << bit);
}

void		parsing_elem(char *str, t_data *d)
{
	while (*str == ' ')
		str++;
	if (!ft_strncmp("NO ", str, 3))
		!d->texture.no.height ? fill_str(0, str + 3, d, &d->texture.no)
		: ft_error("Error NO Texture\n", d, 0);
	if (!ft_strncmp("SO ", str, 3))
		!d->texture.so.height ? fill_str(1, str + 3, d, &d->texture.so)
		: ft_error("Error SO Texture\n", d, 0);
	if (!ft_strncmp("WE ", str, 3))
		!d->texture.we.height ? fill_str(2, str + 3, d, &d->texture.we)
		: ft_error("Error WE Texture\n", d, 0);
	if (!ft_strncmp("EA ", str, 3))
		!d->texture.ea.height ? fill_str(3, str + 3, d, &d->texture.ea)
		: ft_error("Error EA Texture\n", d, 0);
	if (!ft_strncmp("S ", str, 2))
		!d->texture.sp.height ? fill_str(4, str + 2, d, &d->texture.sp)
		: ft_error("Error S Texture\n", d, 0);
	if (!ft_strncmp("F ", str, 2))
		fill_int_rgb(5, str + 2, &d->texture.f, d);
	if (!ft_strncmp("C ", str, 2))
		fill_int_rgb(6, str + 2, &d->texture.c, d);
	if (!ft_strncmp("R ", str, 2))
		fill_int(7, str + 2, d, &(d->texture.bit_texture));
}
