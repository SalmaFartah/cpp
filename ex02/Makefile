CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	tests.cpp\
		Account.cpp\

OBJ = $(SRC:.cpp=.o)

NAME = bank

%.o : %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ) Account.hpp
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re: fclean all

ac: all clean