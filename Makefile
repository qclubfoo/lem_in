NAME = lem_in

FLAGS = -Wall -Wextra -Werror -g

INCLUDES = ./libft/

FILES = ft_atoi_err.c ft_atoi.c ft_bzero.c ft_strchr.c ft_strcmp.c ft_strlen.c ft_strncpy.c ft_strsplit.c ./src/*.c

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
