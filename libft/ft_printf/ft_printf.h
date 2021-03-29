/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:53:38 by jopaning          #+#    #+#             */
/*   Updated: 2020/10/01 11:08:57 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_printf
{
	int		flag_minus;
	int		flag_zero;
	int		flag_dot;
	int		flag_star_w;
	int		flag_star_p;
	int		width;
	int		precision;
	char	c_conversion;
	int		arg_counter;
	char	*format_cp;
	int		st_counter;
	void	*cp_pointer;
}				t_printf;

int				ft_printf(const char *str, ...);
void			ft_putstr_ct(t_printf *st_arg, char *str);
void			ft_putchar_ct(t_printf *st_arg, char c);
void			ft_printer(t_printf *st_arg, va_list args);
void			printf_arg(const char **format, va_list args, int *counter);
char			*ft_precis(t_printf *st_arg, char *d_temp, int d);
void			ft_conv_u(t_printf *st_arg, unsigned int u);
void			ft_conv_x(t_printf *st_arg, unsigned int x);
void			ft_conv_c(t_printf *st_arg, char c);
void			ft_conv_s(t_printf *st_arg, char *s);
void			ft_conv_p(t_printf *st_arg, unsigned long long p);
void			ft_conv_verif(t_printf *st_arg, char *d_temp);
void			ft_conv_d(t_printf *st_arg, int d);
void			ft_putstr_fd(char const *str, int fd);
void			ft_putchar_fd(char c, int fd);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *str);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strdup(const char *str);
char			*ft_strnew(size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_tolower(int c);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_strdel(char **as);
char			*ft_toupper_str(char *str);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*ft_itoa_base(size_t value, size_t base);

#endif
