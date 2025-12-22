NAME = Span

SRCS = src/main.cpp \
		src/Span.cpp

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS_DIR = objs
OBJS = $(SRCS:src/%.cpp=$(OBJS_DIR)/%.o)

RM = rm -rf
MKDIR = mkdir -p

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJS_DIR)/%.o: src/%.cpp
	@$(MKDIR) $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
