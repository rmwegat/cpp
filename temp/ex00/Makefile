# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldick <ldick@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 19:28:14 by ldick             #+#    #+#              #
#    Updated: 2025/08/20 13:31:17 by ldick            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

#################################################################################################
#											Colors												#
#################################################################################################

CLR_RMV		:= \033[0m
RED			:= \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
BOLD_BLUE	:= \033[0;34m
NC			:= \033[0m

#################################################################################################
#											Flags												#
#################################################################################################

COMPILER	=	c++
CFLAGS		=	-std=c++98 -g -Wall -Wextra -Werror
ERROR_FILE	=	error.log

#################################################################################################
#											Sources												#
#################################################################################################

SRCS			=	main.cpp BitcoinExchange.cpp

OBJS			=	$(SRCS:%.c=bin/%.o)

#################################################################################################
#											Rules												#
#################################################################################################

all:			$(NAME)

bin:
				@echo "\t\t\t$(BLUE) Making bin directory"
				@mkdir -p bin/

bin/%.o:		srcs/%.c | bin
				@echo "$(GREEN) Compiling $(Compiler) $(CLR_RMV) -c -o $(YELLOW) $@ $(CYAN) $^ $(GREEN) $(CFLAGS) $(GREEN) $(NC)"
				@$(COMPILER) -c -o $@ $^ $(EXTRA_FLAGS) $(CFLAGS) $(INCLUDES) 2> $(ERROR_FILE) || (cat $(ERROR_FILE) && echo "$(RED)Compilation failed :0\nfailed file: \t\t$(YELLOW)$<$(NC)\n\n" && exit 1$(NC))

$(NAME): $(OBJS)
				@$(COMPILER) -o $(NAME) $(OBJS) $(CFLAGS)
				@echo "\t\t\t\t$(RED) compilation success :3$(NC)"

clean:
				@rm -rf bin
				@rm -f $(ERROR_FILE)

fclean:			clean
				@rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re