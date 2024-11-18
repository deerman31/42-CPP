NAME		:= RPN 
OBJ_DIR		:= obj

SRC_DIR		:= ./

CXX			:= c++
CXXFLAGS	:= -Wall -Werror -Wextra -std=c++98
# CXXFLAGS	+= -g -fsanitize=address

SRCS_NAME	:= main.cpp RPN.cpp

SRCS		:= $(addprefix $(SRC_DIR)/, $(SRCS_NAME))
OBJECTS		:= $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

SHELL		:= fish

all: $(NAME)

$(NAME):	$(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

test:	re
		$(SHELL) ./test.sh

.PHONY: all fclean clean re test
