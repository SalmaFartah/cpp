CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address

NAME = RPN

SRC =	main.cpp RPN.cpp

INC =	RPN.hpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp $(INC)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

ac : all clean
