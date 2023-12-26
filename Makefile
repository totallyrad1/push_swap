NAME = push_swap
BNAME = checker
SOURCES = push_swap.c moves1.c moves2.c moves3.c printingtools.c sortingfunctions.c tools.c helpers.c pivotessorting.c ft_strjoin.c ft_split.c movesapply.c
BSOURCES = checker.c moves1.c moves2.c moves3.c printingtools.c sortingfunctions.c tools.c helpers.c pivotessorting.c ft_strjoin.c ft_split.c movesapply.c
CC = cc 
FLAGS = -Wall -Wextra -Werror
OBJECT = ${SOURCES:.c=.o} 
BOBJECT = ${BSOURCES:.c=.o} 

all : $(NAME)

$(NAME): $(OBJECT)
	$(CC) $(FLAGS) -o $@ $^

%.o: %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o  $@
	
bonus : $(BNAME)

$(BNAME): $(BOBJECT)
	$(CC) $(FLAGS) -o $@ $^

clean:
	rm -f $(OBJECT)

bonus_clean:
	rm -f $(BOBJECT)
	
fclean: clean bonus_clean
	rm -f $(BNAME)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus_clean