NAME		:=	EX
OBJ_DIR		:=	obj
SRC_DIR		:=	src

CXX			:=	c++
CXXFLAGS	:=	-Wall -Werror -Wextra -std=c++98
#CXXFLAGS	+=	-g -fsanitize=address
HEADERS		:=  includes

SRCS_NAME	:=	main.cpp Replace.cpp get_File.cpp str_Convert.cpp output_File.cpp \

SRCS	:= $(addprefix $(SRC_DIR)/, $(SRCS_NAME))
OBJECTS	:= $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME):	$(OBJECTS)
	$(CXX) $(CXXFLAGS) -I $(HEADERS) -o $(NAME) $(OBJECTS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I $(HEADERS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
