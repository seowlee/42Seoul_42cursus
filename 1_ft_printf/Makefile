# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seowoo <seowoo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/06 16:10:35 by seowoo            #+#    #+#              #
#    Updated: 2021/04/06 18:01:12 by seowoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFTDIR = ./libft
LIBFTFILE = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = ft_atoi_printf.c \
		ft_itoa_printf.c \
		ft_parse.c \
		ft_print_len.c \
		ft_printf.c \
		ft_type.c

SRCS_B =

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTFILE) $(NAME)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

bonus: $(OBJS_B)
	$(AR) $(NAME) $(OBJS_B)

clean:
	make -C $(LIBFTDIR) clean
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	make -C $(LIBFTDIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re