# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akadi <akadi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 16:11:29 by akouame           #+#    #+#              #
#    Updated: 2023/06/24 12:11:58 by akadi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ircserv

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

RM = rm -rf

src = main.cpp ft_irc.cpp checkArguments.cpp outils.cpp client_irc.cpp ParsingUtils.cpp Channel.cpp

obj = $(src:.cpp=.o)

hdr = ft_irc.hpp client_irc.hpp Channel.hpp

all : $(NAME)

$(NAME) : $(obj)
	$(CC) -lcurl $(FLAGS) $(obj) -o $(NAME)

%.o : %.cpp  $(hdr)
	$(CC) $(FLAGS) $< -c
clean :
	$(RM) $(obj)

fclean : clean
	$(RM) $(NAME)

re : fclean all