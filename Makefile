# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akouame <akouame@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 14:42:02 by akouame           #+#    #+#              #
#    Updated: 2023/06/08 14:43:48 by akouame          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ircserv
SRCS =  main.cpp server.cpp
OBJS = $(SRCS:.cpp=.o)
FLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++
HEADER = server.hpp 

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY	:	all clean fclean re