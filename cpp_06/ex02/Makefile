CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = identify

SRC =	main.cpp Base.cpp

INC =	Base.hpp B.hpp A.hpp C.hpp

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
