COMPILE = cc -Wall -Wextra -Werror -g
NAME = push_swap
SRC = srcs/push_swap.c srcs/ft_atol.c srcs/indexing.c srcs/free_my_mans.c\
srcs/lst_manipulation.c srcs/movers.c srcs/radix.c srcs/low_sort.c
OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): Makefile push_swap.h $(OBJ)
	@make all -C libft
	@$(COMPILE) $(SRC) ./libft/libft.a -o $(NAME) 
clean:
	@make clean -C libft
	@rm -f $(OBJ)
	@echo 'all clean!! :)'

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo 'all clean!! :)'

re: fclean all

.PHONY: all re clean flclean
