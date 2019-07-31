CC = gcc

NAME = visualizer

FLAGS = -Wall -Wextra -Werror -g

IDIR = ./inc

CFLAGS = -I libSDL/SDL2.framework/Headers \
         -I libSDL/SDL2_image.framework/Headers -I./inc/

# LIBFT = libft/

# LIBVEC = vector_lib/

SDL2_F    = -framework SDL2 -framework SDL2_image -F ./libSDL/

DIR_S = ./

DIR_O = ./

HEADER = includes

# _DEPS = rt.h

# DEPS = $(patsubst %,$(HEADER)/%,$(_DEPS))

SOURCES = main.c

# SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

# OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: obj $(NAME)

$(NAME): $(OBJS)
		$(CC) -o $(NAME) $(SOURCES) $(FLAGS) $(CFLAGS) $(SDL2_F)

obj:
		mkdir -p objects

# $(DIR_O)/%.o: $(DIR_S)/%.c $(DEPS)
# 		$(CC) -c -o $@ $< $(FLAGS) $(CFLAGS)

clean:
		rm -f $(OBJS)
		rm -rf $(DIR_O)

fclean: clean
		rm -f $(NAME)

re: fclean all
