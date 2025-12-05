CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = exec

SRC =	main.cpp Cure.cpp Ice.cpp AMateria.cpp Character.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp Cure.hpp Ice.hpp AMateria.hpp Character.hpp ICharacter.hpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

ac : all clean
