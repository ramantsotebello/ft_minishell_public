# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tramants <tramants@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/27 10:56:37 by tramants          #+#    #+#              #
#    Updated: 2018/09/17 14:03:49 by tramants         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strdup.c \
	  ft_strlen.c \
	  ft_strdel.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strchr.c \
	  ft_strsplit.c \
	  ft_wordcountdel.c \
	  ft_wordlendel.c \
	  ft_itoa.c \
	  ft_nbrlen.c \
	  ft_strsplit.c \
	  ft_strtrim.c \
	  ft_spacecount.c \
	  ft_strrchr.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_islower.c \
	  ft_isupper.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_isprint.c \
	  ft_isascii.c \
	  ft_bzero.c \
	  ft_memset.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_memalloc.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strnew.c \
	  ft_strclr.c \
	  ft_memdel.c \
	  ft_atoi.c  

FLAGS = -Wextra -Wall -Werror
HEADER = libft.h
OBJECTS = *.o

all: $(NAME)
$(NAME): 
	gcc -c $(SRC) -I $(HEADER)
	ar rc $(NAME) $(OBJECTS)

clean:
	rm -f *.o

fclean: 
	rm -f $(NAME)

re: fclean all clean

ultra: re 
	gcc main.c $(NAME) $(FLAGS)

ultraclean: fclean clean
	rm -f a.out

