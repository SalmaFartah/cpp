CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = exec

SRC =	main.cpp

INC =	whatever.hpp

OBJ = $(SRC:.cpp=.o)

%.o : %.cpp $(INC)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

ac : all clean
