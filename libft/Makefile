# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 10:28:19 by erbuffet          #+#    #+#              #
#    Updated: 2025/02/10 19:54:42 by erbuffet         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
SRC = ft_putnbr_fd.c \
ft_bzero.c ft_calloc.c ft_isascii.c ft_isalnum.c ft_toupper.c   \
ft_isalpha.c ft_isdigit.c ft_isprint.c  ft_itoa.c ft_atoi.c     \
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c    \
ft_putchar_fd.c ft_putendl_fd.c ft_strncmp.c ft_strnstr.c       \
ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
ft_strrchr.c ft_strstr.c ft_strtrim.c ft_substr.c ft_tolower.c  \
ft_strcmp.c\

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	$(AR) rcs $(NAME) $(OBJ)

%.o : %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@
# ( $@ ) for the object file name and ( $< ) for the source file name.

all: $(NAME)

clean:       
	rm -f $(OBJ)
# rm for remove, -f for files, $(OBJ) for .o.

fclean: clean
	rm -f $(NAME)
# rm for remove, -f for files, $(NAME) for prog name.

re: fclean $(NAME)

.PHONY: all clean fclean re