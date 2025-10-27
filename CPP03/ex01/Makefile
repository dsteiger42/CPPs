NAME = ScavTrap

SRCS = src/main.cpp \
		src/ClapTrap.cpp \
		src/ScavTrap.cpp
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