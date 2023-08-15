CC = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp Bureaucrat.cpp 
OBJS = $(SRCS:.cpp=.o)
NAME = Bureaucrat

all : $(NAME)
  
$(NAME) : $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $^

%.o : %.cpp
	$(CC) $(CXXFLAGS) -o $@ -c $^
 
clean :
	rm  -rf $(OBJS)
fclean :
	$(MAKE) clean
	rm -rf $(NAME)
re :
	$(MAKE) fclean
	$(MAKE) all
.PHONY : clean, fclean, re, all