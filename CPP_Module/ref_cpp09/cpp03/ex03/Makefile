CC = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = ClapTrap.cpp main.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = DiamondTrap
  
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