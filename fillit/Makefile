#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: bgrec <bgrec@student.42.fr>                +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/12/03 15:59:33 by bgrec             #+#    #+#             *#
#*   Updated: 2016/12/28 13:22:48 by bgrec            ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = fillit

SRC = ft_test_piece.c ft_put_tetrominoes.c ft_read_file.c ft_solve_square.c \
	  ft_print_result.c main.c

INC = includes/

OBJ = $(SRC:.c=.o)

INCLIB = libft/
LIBFT = ./libft/libft.a

$(NAME):	$(LIBFT)
			gcc -Wall -Wextra -Werror -I$(INCLIB) -I$(INC) -c $(SRC)
			gcc -Wall -Wextra -Werror -L libft/ -lft -o $(NAME) $(OBJ)

all: 		$(NAME)

clean:
			rm -f $(OBJ)
			make -C libft/ clean 

fclean: 	clean
			rm -f $(NAME)
			make -C libft/ fclean

re: 		fclean all

libft : 	$(LIBFT)

$(LIBFT):
			make -C libft/ fclean && make -C libft/
		
