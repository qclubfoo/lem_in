# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 18:42:35 by sbrella           #+#    #+#              #
#    Updated: 2019/07/31 18:05:32 by sbrella          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ./ft_*.c

OUT = ./*.o

INCLUDES = ./

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):

	@gcc $(FLAGS) -c $(SRCS) -I $(INCLUDES)
	@ar rc $(NAME) $(OUT)
	@ranlib $(NAME)

clean:
	@rm -f $(OUT)

fclean: clean
	@rm -f $(NAME)

re: fclean all
