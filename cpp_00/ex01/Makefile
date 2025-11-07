CC = c++

CXXFLAGS = -Wall -Wextra -Werror #-std=c++98

SRC =	main.cpp\
		Contact.cpp\
		PhoneBook.cpp

OBJ = $(SRC:.cpp=.o)

NAME = phonebook


%.o : %.cpp PhoneBook.hpp Contact.hpp
	@$(CC) $(CXXFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ) 
	@$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re: fclean all

ac: all clean