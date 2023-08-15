CC = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp Floor.cpp main.cpp 
OBJS = $(SRCS:.cpp=.o)
NAME = AMateria

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
.PHONY : clean, fclean, re