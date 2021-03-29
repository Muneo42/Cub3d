/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 22:54:47 by jopaning          #+#    #+#             */
/*   Updated: 2021/03/29 14:18:37 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		check_map2(t_data *d, int j)
{
	int size;

	size = ft_strlen(d->map.tab_map[j]) - 1;
	if (size > d->map.x_max)
		d->map.x_max = size + 1;
	if (size == ((int)ft_strlen(d->map.tab_map[j - 1]) - 1))
	{
		if (d->map.tab_map[j][size] != '1')
			ft_error(ERROR_MAP_WALL, d, 1);
	}
	else
	{
		while (size < ((int)ft_strlen(d->map.tab_map[j - 1]) - 1))
			if (d->map.tab_map[j - 1][size++] != '1')
				ft_error(ERROR_MAP_WALL, d, 1);
		while (size > ((int)ft_strlen(d->map.tab_map[j - 1]) - 1))
			if (d->map.tab_map[j][size--] != '1')
				ft_error(ERROR_MAP_WALL, d, 1);
	}
}

void		*check_map(t_data *d)
{
	int j;

	j = 0;
	if (!(is_tab_full(d->map.tab_map[j], '1')))
		ft_error(ERROR_MAP_WALL, d, 1);
	while (++j < d->map.line_len)
	{
		if (d->map.tab_map[j][0] != '1')
			ft_error(ERROR_MAP_WALL, d, 1);
		check_map2(d, j);
	}
	if (!(is_tab_full(d->map.tab_map[j], '1')))
		ft_error(ERROR_MAP_WALL, d, 1);
	d->map.y_max = ++j;
	return (&d->map);
}

void		map_str(char *str, t_map *map, t_data *d)
{
	t_lmap	*line;
	t_lmap	*mouv;

	if (!(line = malloc(sizeof(t_map))))
		ft_error("Error\n MALLOC DIDN'T GO WELL", d, 0);
	line->str = ft_replace(str, ' ', '1');
	printf("str = %s\n", line->str);
	line->size = ft_strlen(line->str);
	map->tab_line++;
	line->next = 0;
	if (!map->line)
		map->line = line;
	else
	{
		mouv = map->line;
		while (mouv->next != 0)
		{
			mouv = mouv->next;
		}
		mouv->next = line;
	}
}

void		full_map(t_map *map, t_data *d)
{
	t_lmap	*mouv;
	int		i;

	i = 0;
	if (!(map->tab_map = (char **)malloc(sizeof(char *) * (map->tab_line + 1))))
	{
		clear_lstmap(d->map.line);
		ft_error(ERROR_MALLOC, d, 0);
	}
	mouv = map->line;
	while (mouv->next)
	{
		map->tab_map[i++] = mouv->str;
		mouv = mouv->next;
		map->line_len++;
	}
	map->tab_map[i++] = mouv->str;
	map->tab_map[i] = 0;
}
