SRCS = $(wildcard *_mondat.c)
	  
OBJS = $(SRCS:.c=.o)

BSRCS = ${wildcard *_bonus.c}

BOBJS = $(BSRCS:.c=.o)

NAME1 = push_swap

NAME2 = checker

FLAGS = -Wall -Wextra -Werror

RM = rm -f

CC = cc

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME1):	$(OBJS)
		${CC} -o $(NAME1) $(OBJS)

$(NAME2):	$(BOBJS)
		${CC} -o $(NAME2) $(BOBJS)

all:	$(NAME1)

bonus:	$(NAME2)

clean:
	$(RM) $(OBJS) $(BOBJS)
	
fclean: clean
	$(RM) $(NAME1) $(NAME2)

re:	fclean all

.PHONY: clean fclean re all
