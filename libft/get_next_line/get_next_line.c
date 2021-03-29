/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:16:42 by jopaning          #+#    #+#             */
/*   Updated: 2021/03/25 10:23:57 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_new_line(char **s, char **line, int fd, int ret)
{
	char	*temp;
	int		len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		if (!(*line = ft_substr(s[fd], 0, len)))
			return (-1);
		if (!(temp = ft_strdup(s[fd] + len + 1)))
			return (-1);
		free(s[fd]);
		s[fd] = temp;
		(s[fd][0] == '\0') ? ft_strdel(&s[fd]) : 0;
	}
	else if (s[fd][len] == '\0')
	{
		if (ret == BUFFER_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
		return (0);
	}
	return (1);
}

int			ft_malloc(char **line)
{
	if (!(*line = malloc(sizeof(char))))
		return (-1);
	(*line)[0] = 0;
	return (0);
}

int			get_next_line(int fd, char **line)
{
	int			verif;
	char		buffer[BUFFER_SIZE + 1];
	char		*temp;
	static char	*str[4096];

	if (fd < 0 || line == 0)
		return (-1);
	while ((verif = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[verif] = '\0';
		(str[fd] == NULL) ? str[fd] = ft_strnew(1) : str[fd];
		temp = ft_strjoin(str[fd], buffer);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (verif < 0)
		return (-1);
	if (verif == 0 && (str[fd] == 0 || str[fd][0] == '\0'))
		return (ft_malloc(line));
	return (ft_new_line(str, line, fd, verif));
}
