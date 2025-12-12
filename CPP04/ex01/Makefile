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

OBJS_DIR = objs
OBJS = $(SRCS:src/%.cpp=$(OBJS_DIR)/%.o)

RM = rm -rf
MKDIR = mkdir -p

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS_DIR)/%.o: src/%.cpp
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re