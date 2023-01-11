# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 17:15:13 by pcamaren          #+#    #+#              #
#    Updated: 2023/01/11 11:04:22 by pcamaren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	ft_containers_tester


TESTS =	main\
		vector_test\
		map_test\
		stack_test

INCLUDES	=	-I includes/
CXXFLAGS	=	-g -Wall -Wextra -Werror -MMD -std=c++98
CXX			=	clang++

SRC_DIR		=	tests/
OBJS_DIR	=	objs/
INCL_DIR	=	includes/
DEPS_DIR	=	deps/

DIR_O	=	@mkdir -p objs/
DIR_D	=	@mkdir -p deps/

RM_FILE	= rm -f
RM_DIR	= rm -rf

LIST_C	= $(addprefix $(SRC_DIR), $(TESTS))
LIST_O	= $(addprefix $(OBJS_DIR), $(TESTS))
LIST_D	= $(addprefix $(DEPS_DIR), $(TEST))

SRCS	= $(addsuffix .cpp, $(LIST_C))
OBJS	= $(addsuffix .o, $(LIST_O))
DEPS	= $(OBJS:.o=.d)

$(OBJS_DIR)%.o	:	$(SRC_DIR)%.cpp
				$(DIR_O)
				$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(NAME)	:		$(OBJS)
				$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all	:			$(NAME)


compare : $(NAME)
	$(CXX) $(CXXFLAGS) $(OBJS) -D LIB="std"  -o std_containers_tester
	./$(NAME) > ft_out
	./std_containers_tester > std_out
	diff ft_out std_out

clean	:		
				rm -rf $(OBJS_DIR) $(DEPS_DIR)

fclean	: clean
		rm -f $(NAME)
		rm -rf std_containers_tester
		rm  -rf std_out ft_out
		
re	  : 		fclean all

.PHONY  : 		all fclean re

-include	$(DEPS)