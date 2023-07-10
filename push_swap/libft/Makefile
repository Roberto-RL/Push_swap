# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 15:34:37 by rrimonte          #+#    #+#              #
#    Updated: 2023/02/14 12:01:59 by rrimonte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	libft.a
HEADERS		= 	libft.h
SRCS		=	ft_bzero.c \
				ft_strlen.c \
				ft_strchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_split.c
OBJS		= 	${SRCS:.c=.o}
CC			= 	gcc
AR			= 	ar rcs
CFLAGS		= 	-Wall -Wextra -Werror
CFLAGS2		= 	-Wall -Wextra -Werror -g3 -fsanitize=address
RM			= 	rm -rf


all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus
