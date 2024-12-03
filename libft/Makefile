# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irlozano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/24 18:19:17 by irlozano          #+#    #+#              #
#    Updated: 2024/01/20 16:47:32 by irlozano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
RM = rm -f
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strlen.c \
	   ft_isdigit.c \
	   ft_strrchr.c \
	   ft_isprint.c \
	   ft_putchar_fd.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_atoi.c \
	   ft_itoa.c \
	   ft_putendl_fd.c \
	   ft_strlcat.c \
	   ft_substr.c \
	   ft_putnbr_fd.c \
	   ft_strlcpy.c \
	   ft_tolower.c \
	   ft_putstr_fd.c \
	   ft_strlen.c \
	   ft_toupper.c \
	   ft_isalnum.c \
	   ft_split.c \
	   ft_strmapi.c \
	   ft_isalpha.c \
	   ft_strchr.c \
	   ft_strncmp.c \
	   ft_isascii.c \
	   ft_strdup.c \
	   ft_strnstr.c \
	   ft_atoll.c \
	   display_error.c \
	   ft_sqrt.c \

BONUS_SRCS = ft_lstnew_bonus.c \
			 ft_lstadd_front_bonus.c \
			 ft_lstsize_bonus.c \
			 ft_lstlast_bonus.c \
			 ft_lstadd_back_bonus.c \
			 ft_lstdelone_bonus.c \
			 ft_lstclear_bonus.c \
			 ft_lstiter_bonus.c \
			 ft_lstmap_bonus.c \

OBJS = $(SRCS:%.c=%.o)

BONUS_OBJS := $(BONUS_SRCS:%.c=%.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
