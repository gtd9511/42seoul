CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = PhoneBook.cpp Contact.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = PhoneBook

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