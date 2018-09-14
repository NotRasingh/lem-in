# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rasingh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/23 11:19:30 by rasingh           #+#    #+#              #
#    Updated: 2018/09/14 12:20:33 by rasingh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
SOURCES = srcs/main.c srcs/path.c srcs/init.c
INCLUDES = includes/libft/libft.a includes/gnl/get_next_line.c

$(NAME):
	@make -C includes/libft
	@gcc -Wall -Werror -Wextra $(SOURCES) $(INCLUDES) -o $(NAME)
	@echo "\033[1;32;4mCOMPILING SUCCESSFUL"

all: $(NAME)

clean:
	@make clean -C includes/libft
	@rm -f $(NAME)
	@echo "\033[1;34;4mCLEAN SUCCESSFUL\033[0m"

fclean: clean
	@make fclean -C includes/libft
	@rm -f $(NAME)

re: fclean all
