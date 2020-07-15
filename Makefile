# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tramants <tramants@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/13 18:03:08 by tramants          #+#    #+#              #
#    Updated: 2018/09/25 15:16:33 by tramants         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
OBJ = *.o
DEPS = get_next_line.c mini_shell.c libft/libft.a ft_useful_funcs_1.c\
		ft_handler_funcs.c ft_cd.c ft_echo.c ft_getenv.c ft_setenv.c\
		ft_unsetenv.c ft_process_basic_args.c ft_init.c ft_useful_funcs_2.c
NAME = minishell
HEADER = get_next_line.h mini_shell.h libft/libft.h
MY_LIBFT = libft

all: $(NAME)

$(NAME): my_libft
	gcc $(FLAGS) $(DEPS)
	mv a.out minishell

.PHONY: my_libft

my_libft:
	$(MAKE) -C $(MY_LIBFT) re

clean: 
	rm *.o 

fclean:
	rm -f minishell

re: fclean all
