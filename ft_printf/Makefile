# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pshamkha <pshamkha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 19:01:19 by pshamkha          #+#    #+#              #
#    Updated: 2024/03/19 19:56:13 by pshamkha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

LIBFT_DIR = libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

SRCS = \
       ft_printf.c \
       ft_putnbrf_base.c \
       ft_putcharf.c \
       ft_putptrf.c \
       ft_putstrf.c \
       ft_putnbrf.c \
       ft_get_flags.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)$(LIBFT_NAME) $(NAME)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
