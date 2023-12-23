NAME = push_swap
SOURCES = push_swap.c moves1.c moves2.c moves3.c printingtools.c sortingfunctions.c tools.c helpers.c
CC = cc 
FLAGS = -Wall -Wextra -Werror
OBJECT = ${SOURCES:.c=.o} 

all : push_swap

$(NAME): $(OBJECT)
	$(CC) $(FLAGS) -o $@ $^

%.o: %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o  $@

clean:
	rm -f $(OBJECT)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re