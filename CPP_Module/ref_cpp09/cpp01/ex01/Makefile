CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = zombieHorde.cpp Zombie.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = ZombieHorde

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

clean : 
	rm  -rf $(OBJS)
fclean :
	$(MAKE) clean
	rm -rf $(NAME)
re : 
	$(MAKE) fclean
	$(MAKE) all
.PHONY : clean, fclean, re