# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 16:27:01 by pcamaren          #+#    #+#              #
#    Updated: 2022/12/02 16:36:11 by pcamaren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=containers_test
CODEDIRS=. ./tests/
INCDIRS=. ./includes/

CC=clang++
DEPFLAGS=-MP -MD
CFLAGS=-Wall -Wextra -Werror -std=c++98 $(foreach D, $(INCDIRS), -I$(D)) $(DEPFLAGS)

CFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.c))
OBJECTS=$(patsubst %.c %.o, $(CFILES))
DEPFILES=$(patsubst %.c, %.d, $(CFILES))

all: $(NAME)

