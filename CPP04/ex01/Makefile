NAME = Brain

SRCS = src/main.cpp \
		src/Animal.cpp \
		src/Cat.cpp \
		src/Dog.cpp \
		src/WrongAnimal.cpp \
		src/WrongCat.cpp \
		src/Brain.cpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re