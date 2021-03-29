# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/24 22:51:44 by jopaning          #+#    #+#              #
#    Updated: 2021/03/29 15:48:35 by jopaning         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/main.c \
			parsing/parsing.c \
			parsing/parsing_elem.c \
			parsing/full_map.c \
			parsing/error_free.c \
			parsing/init_structures.c \
			srcs/move_player.c \
			srcs/image.c \
			srcs/raycasting.c \
			srcs/radar.c \
			srcs/vector.c \
			srcs/utils.c \
			srcs/bmp.c \
			srcs/minimap.c \
			srcs/sprite.c

OBJS =		$(SRCS:.c=.o)

NAME = 		cub3d

FLAGS =		-Wall -Werror -Wextra -g

LIB_FLAGS = -Lminilibx_linux libft/libft.a -lX11 -lXext -lm -lbsd -lmlx

.c.o:
			clang -c $< -o $(<:.c=.o) $(FLAGS)

$(NAME):	$(OBJS)
			make -C libft
			make -C minilibx_linux
			clang $(OBJS) $(FLAGS) -o $(NAME) $(LIB_FLAGS)

all: 		$(NAME)

clean:
			make -C libft -f Makefile clean
			rm -f $(OBJS)

fclean:		clean
			make -C libft -f Makefile fclean
			make -C minilibx_linux -f Makefile clean
			rm -f $(NAME)
			rm -f image.bmp

re: 		fclean all

norm:
			~/.norminette/norminette.rb main.c
			~/.norminette/norminette.rb cub3d.h
			~/.norminette/norminette.rb parsing
			~/.norminette/norminette.rb srcs
			~/.norminette/norminette.rb libft
