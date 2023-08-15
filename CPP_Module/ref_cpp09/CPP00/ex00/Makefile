CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g -fsanitize=address
SRCS = megaphone.cpp
OBJS = $(SRCS:.c=.o)
NAME = megaphone

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $< -o $(NAME) 

clean : 
	rm $(OBJS)
fclean :
	$(MAKE) clean
	rm $(NAME)
re : 
	$(MAKE) fclean
	$(MAKE) all
.PHONY : clean, fclean, re