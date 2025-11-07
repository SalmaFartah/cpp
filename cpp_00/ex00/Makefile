CC = c++

CXXFLAGS = -Wall -Wextra -Werror #-std=c++98

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

NAME = megaphone

%.o : %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re: fclean all