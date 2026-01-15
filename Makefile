##
## EPITECH PROJECT, 2025
## my_printf
## File description:
## Makefile
##

CC = clang
CFLAGS = -g

GREEN = [1;32m
CYAN = [1;36m
YELLOW = [1;33m
RED = [1;31m
MAGENTA = [1;35m
BOLD = [1m
RESET = [0m

SRC	= 	src/my_put_nbr.c \
		src/my_putstr.c \
		src/my_printf.c \
		src/my_unsigned_put_nbr.c	\
		src/my_put_oct.c	\
		src/my_put_hex.c	\
		src/my_put_ptr.c	\
		src/my_put_flt.c	\
		src/my_put_sci.c

SRCTEST = example.c

OBJ	= 	$(SRC:.c=.o)

OBJTEST = $(SRCTEST:.c=.o)

NAME	= 	libprintf.a
NAME_EXAMPLE = example

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $< 
	@printf "  $(GREEN)󰆍 $(RESET) %s\n" $< 

all:	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@printf "  $(CYAN)󰌷 $(RESET) $(BOLD)%s$(RESET)\n" $(NAME)

clean:
	@rm -f $(OBJ) $(OBJTEST)
	@printf "  $(YELLOW)󰃢 $(RESET) objects\n"

fclean: clean
	@rm -f $(NAME) $(NAME_EXAMPLE)
	@printf "  $(RED)󰩹 $(RESET) %s %s\n" $(NAME) $(NAME_EXAMPLE)

re: fclean all

example:	re
	@$(CC) $(SRCTEST) -L./ -lprintf -o $(NAME_EXAMPLE)
	@printf "  $(CYAN) $(RESET) $(BOLD)%s$(RESET)\n" $(NAME_EXAMPLE)

run:	example
	@./$(NAME_EXAMPLE)
	@printf "  $(MAGENTA)󰐊 $(RESET) $(BOLD)%s$(RESET)\n" $(NAME_EXAMPLE)

epiclang: fclean
	@$(MAKE) --no-print-directory CC=epiclang CFLAGS="-Werror" all
	@$(MAKE) --no-print-directory fclean


.PHONY: all clean fclean re example run epiclang
