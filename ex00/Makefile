SRC_PATH = ./
HEAD_PATH = ./
OBJS_PATH = objs/

SRC = $(wildcard *.cpp)

OBJS = $(patsubst $(SRCS_PATH)%.cpp, $(OBJS_PATH)%.o, $(SRC))
DEPS = $(patsubst $(SRCS_PATH)%.cpp, $(OBJS_PATH)%.d, $(SRC))

NAME = easy_find

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98 -g3

$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(FLAGS) -MMD -MP -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $@

-include $(DEPS)

all: $(NAME)

clean:
	@rm -rf $(OBJS_PATH)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re