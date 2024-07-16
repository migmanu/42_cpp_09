CXXFLAGS = -Werror -Wextra -Wall -std=c++98 -g
CXX = c++
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = PmergeMe

# Default rule
all: $(NAME)

# Rule to create the executable
$(NAME): $(OBJS)
	@$(CXX) -o $@ $^

# Rule to create object files
%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean object files
clean:
	@rm -f $(OBJS)

# Rule to clean everything
fclean: clean
	@rm -f $(NAME)

# Rule to recompile everything
re: fclean all

# Rule to run program
run : all
	./$(NAME)

# Phony targets
.PHONY: all clean fclean re run
