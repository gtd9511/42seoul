CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = newZombie.cpp randomChump.cpp Zombie.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = Zombie

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