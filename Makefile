NAME = lem-in

FLAGS = -Wall -Wextra -Werror

INCLUDES = ./libft/

FILES = ./src/checking_hash.c ./src/checking_map_help.c ./src/checking_map.c \
		./src/connected.c ./src/connection.c ./src/extra_checking.c \
		./src/main.c ./src/making_bonds.c ./src/making_map.c ./src/making_rooms.c \
		./src/path.c ./src/read.c ./src/rooms_adding.c ./src/validate.c

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
