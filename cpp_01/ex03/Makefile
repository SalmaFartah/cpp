CXX = c++

CXXFLAGS = -Wall -Wextra -Werror #-std=c++98

NAME = Humans

SRC =	main.cpp\
		HumanA.cpp\
		Weapon.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp HumanA.hpp Weapon.hpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

ac : all clean