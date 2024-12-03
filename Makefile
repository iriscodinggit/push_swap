NAME	=	push_swap
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

HEADER	=	./header/push_swap.h
LIBFT	=	./libft/libft.a
OBJFILES	=	./obj/
SRCFILES = sources/*.c

PINK 		:= \033[38;5;218m
			
OBJ		=	$(SRCFILES:$(SRCFILES)%.c=$(OBJFILES)%.o)

all		:	$(NAME)

$(NAME)	 :	$(OBJ)
	@cd libft && make
	@$(CC) $(CFLAGS)  $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\n$(PINK)The programme is ready to sort and rock! 🎸: ./push_swap \"2 0 3 1 5 4\" ✨ \n"


$(OBJFILES)%.o:	$(SRCFILES)%.c $(HEADER)
	@mkdir -p $(OBJFILES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@cd libft && make clean
	@rm -rf $(OBJFILES)

fclean :	clean
	@cd libft && make fclean
	@rm -f $(NAME)

re	:	fclean all

./PHONY: all clean fclean re
