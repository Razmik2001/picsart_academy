NAME		= Graf

CC			= g++

CFLAGS		= -Wall -Wextra -Werror --std=c++11 -g -ggdb3

RM			= rm -f

SRCS		= $(wildcard *.cpp) 

OBJS 		= $(SRCS:.cpp=.o)

%.o:%.c
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS) 
			$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
clean:
			$(RM) $(OBJS) 

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re
