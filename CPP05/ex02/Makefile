NAME       := EX
OBJ_DIR    := obj

SRC_DIR    := ./

CXX        := c++
CXXFLAGS   := -Wall -Werror -Wextra -std=c++98
#CXXFLAGS   += -g -fsanitize=address

SRCS_NAME  :=	main.cpp Bureaucrat.cpp AForm.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp

SRCS       := $(addprefix $(SRC_DIR)/, $(SRCS_NAME))
OBJECTS    := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME):	$(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(DEP_DIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all fclean clean re
