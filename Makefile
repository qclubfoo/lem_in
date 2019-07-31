NAME = lem-in

FLAGS = -Wall -Wextra -Werror -g

INCLUDES = ./libft/

FILES = ./src/*.c

all: $(NAME)

$(NAME):

	@make -C libft/ fclean && make -C libft/
	gcc -o $(NAME) $(FILES) $(FLAGS) ./libft/libft.a -I ./inc/

clean:
	@make -C libft/ clean
	@rm -f *.o

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
