# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 11:50:55 by rrimonte          #+#    #+#              #
#    Updated: 2023/03/16 14:27:18 by rrimonte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
HEADERS			=	push_swap.h
SRCS			=	ft_atoi2.c \
					ft_comands.c \
					ft_comands2.c \
					ft_compare.c \
					ft_errorcheck.c \
					ft_operations.c \
					ft_direcction.c \
					ft_search.c \
					push_swap.c
OBJS			=	$(SRCS:.c=.o)
CC				=	gcc
LIBFT_FOLDER	=	libft/
LIBFT_NAME		=	libft.a
LIBS			=	$(LIBFT_FOLDER)$(LIBFT_NAME)
AR				=	ar rcs
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf
all:
	$(MAKE) -C $(LIBFT_FOLDER)
	$(MAKE) $(NAME)

$(NAME): $(LIBS) $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS)  -o $(NAME)
clean:
	$(MAKE) -C $(LIBFT_FOLDER) clean
	$(RM) $(OBJS)
fclean: clean
	$(MAKE) -C $(LIBFT_FOLDER) fclean
	$(RM) $(NAME)
re: fclean all
