NAME		:=	megaphone
CXX			:=	c++
CXXFLAGS	:=	-Wall -Werror -Wextra -std=c++98
#CXXFLAGS	+=	 -g -fsanitize=address

SRCS	:= megaphone.cpp
OBJECTS	:= $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME):	$(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)

$(OBJECTS): $(SRCS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
