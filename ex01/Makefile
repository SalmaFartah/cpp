CC = c++

CFLAGS = -Wall -Wextra -Werror

SRC =	main.cpp\
		contact.cpp\
		phonebook.cpp

OBJ = $(SRC:.cpp=.o)

NAME = phonebook

%.o : %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re: fclean all

ac: all clean