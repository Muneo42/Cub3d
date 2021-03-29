# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/12 12:49:31 by jopaning          #+#    #+#              #
#    Updated: 2021/03/24 23:53:12 by jopaning         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
 	ft_strmapi.c \
 	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_iswhitespace_bonus.c \
	ft_strnew_bonus.c \
	ft_strncpy_bonus.c \
	ft_lstreverse_bonus.c \
	is_tab_full.c \
	ft_strcmp.c \
	ft_replace.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \

BONUS =	ft_lstnew.c \
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c\

OBJ = $(SRC:.c=.o) 

OBJ_BONUS = $(BONUS:.c=.o)

FLAGS = -Wextra -Wall -Werror

HEADER_DIR = libft.h

CC = gcc $(FLAGS)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER_DIR)
	@ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_BONUS) $(HEADER_DIR)
	@ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

.%.o: .%.c
	$(CC) -c $(SRC)

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
