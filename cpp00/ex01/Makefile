# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 13:03:05 by rwegat            #+#    #+#              #
#    Updated: 2025/03/17 01:37:51 by rwegat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98
CPP = c++

SRCS =	main.cpp\
		PhoneBook.cpp\
		Contact.cpp\

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPP_FLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1;32m ✅ [ex created]\033[0m"

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "\033[0;31m 🗑️  [OBJS deleted]\033[0m"
	
fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31m 🗑️  [ex deleted]\033[0m"

re: fclean all

.SILENT: $(OBJS)

.PHONY: all clean fclean re