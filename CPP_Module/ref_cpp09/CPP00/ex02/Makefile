CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = Account.cpp test.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = Account

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.cpp
	$(CC) $(CFLASGS) -o $@ -c $^

clean : 
	rm  -rf $(OBJS)
fclean :
	$(MAKE) clean
	rm -rf $(NAME)
re : 
	$(MAKE) fclean
	$(MAKE) all
.PHONY : clean, fclean, re