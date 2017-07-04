# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgrec <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/09 14:55:07 by bgrec             #+#    #+#              #
#    Updated: 2017/05/09 15:01:43 by bgrec            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS_DIR = srcs/

SRC =	main.c entries.c fail.c prepass_col_size.c print_dir.c \
		bonus.c print_maj_min.c print_perms.c print_total.c sort.c

SRCS = $(addprefix $(SRCS_DIR),$(SRC))
OBJS = $(patsubst %.c,%.o,$(SRC))

CFLAGS = -Wall -Wextra -Werror -Oz -I includes -I libft/

all: $(NAME)

$(NAME):
		@make -C libft
		@gcc -c -Wall -Wextra -Werror -Oz -I includes -I libft/  $(SRCS)
		@gcc -L libft -lft  $(OBJS) -o $(NAME)
clean:
		@rm -f $(OBJS)
		@make -C libft clean

fclean: clean
		@rm -f $(NAME)
		@make -C libft fclean

re: 	fclean all
