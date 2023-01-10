# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 17:15:13 by pcamaren          #+#    #+#              #
#    Updated: 2023/01/10 04:15:06 by pcamaren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SIMPLE 
NAME			= ft_container_tester
# ******************************************************************************

# SRCS 
SOURCES_FOLDER	= ./tests/
SOURCES			=	main_vector.cpp					
# ******************************************************************************
# INCLUDES
 INCLUDE 		= ./includes/*.hpp
# ******************************************************************************
# FLAGS 
FLAGS 			= --std=c++98
DEPS			= $(INCLUDES)
# ******************************************************************************
# OBJECTS 
OBJECTS_FOLDER 	= ./tester/objects/
OBJECT			= $(SOURCES:.cpp=.o)
OBJECTS		 	= $(addprefix $(OBJECTS_FOLDER), $(OBJECT));
# ******************************************************************************
# RULES 
$(OBJECTS_FOLDER)%.o :	$(SOURCES_FOLDER)%.cpp	$(DEPS) $(INCLUDE) 
	@mkdir -p	$(OBJECTS_FOLDER)
	@echo "Compiling: $<"
	@clang++ -g $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	@clang++ $(FLAGS) -o $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	@echo "Cleaning: $(OBJECTS_FOLDER)"
	@rm -rf $(OBJECTS_FOLDER)
	@echo "Cleaning: ./tester/vectors_output"
	@rm -rf ./tester/vectors_output

fclean: clean
	@echo "Cleaning: $(NAME)"
	@rm -f $(NAME)

re: fclean all
# ******************************************************************************
# RULE TO RUN 
run: $(NAME)
	@./$(NAME)

# ******************************************************************************
