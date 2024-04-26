NAME = pipex

FT_PRINTF_DIR = ft_printf/
FT_PRINTF_NAME = libftprintf.a
FT_PRINTF = $(FT_PRINTF_DIR)$(FT_PRINTF_NAME)

SRCS_DIR = ./srcs/

INCLUDES_DIR = ./includes/

SRCS = \
		$(SRCS_DIR)get_next_line.c \
		$(SRCS_DIR)get_next_line_utils.c \
		$(SRCS_DIR)children.c \
		$(SRCS_DIR)executes.c \
		$(SRCS_DIR)free_pipex.c \
		$(SRCS_DIR)init_pipex.c \
		$(SRCS_DIR)pipex.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra
CC = cc

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(FT_PRINTF_DIR)
	$(CC) $(OBJS) -o $(NAME) $(FT_PRINTF)

%.o: %.c Makefile
	$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDES_DIR)

clean:
	make -C $(FT_PRINTF_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	make -C $(FT_PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
