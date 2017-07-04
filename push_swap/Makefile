# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgrec <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/21 16:49:17 by bgrec             #+#    #+#              #
#    Updated: 2017/06/21 17:00:12 by bgrec            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft/libft.a
NAMEPS = push_swap
NAMEC  = checker
FLAGS = -Wall -Wextra -Werror

PS_SRC	=	push_swap.c freeit.c create_stack.c struct.c sort.c \
			sort2.c rules.c help.c print.c \

C_SRC =		checker.c freeit.c create_stack.c struct.c sort.c \
			sort2.c rules.c help.c print.c \

all: $(NAMEPS) $(NAMEC)

$(NAMEPS): $(PS_SRC)
	@make -C libft/
	@gcc $(FLAGS) $(PS_SRC) $(LIB) -o $(NAMEPS)


$(NAMEC): $(C_SRC)
	@gcc $(FLAGS) $(C_SRC) $(LIB) -o $(NAMEC)

re: fclean all
	@make re -C libft/

clean:
	@make clean -C libft/

fclean: clean
	@make fclean -C libft/
	@rm $(NAMEPS)
	@rm $(NAMEC)

.Phony: all re clean fclean $(NAMEC) $(NAMEPS)
