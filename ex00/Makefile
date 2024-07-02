CXXFLAGS = -Werror -Wextra -Wall -std=c++98 -g
CXX = c++
SRCS = main.cpp BitCoinExchange.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = btc

# Default rule
all: $(NAME)

# Rule to create the executable
$(NAME): $(OBJS)
	@$(CXX) -o $@ $^

# Rule to clean object files
clean:
	@rm -f $(OBJS)

# Rule to clean everything
fclean: clean
	@rm -f $(NAME)

# Rule to recompile everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re run
