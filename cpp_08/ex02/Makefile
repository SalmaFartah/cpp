CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -fsanitize=address -std=c++98

NAME = exec

SRC =	main.cpp

INC =	MutantStack.hpp MutantStack.tpp

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
