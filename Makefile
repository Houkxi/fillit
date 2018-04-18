# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 07:31:59 by mmanley           #+#    #+#              #
#    Updated: 2018/01/05 21:32:46 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	@$(MAKE) -C libft/
	@$(MAKE) -C srcs/
	@$(CC) -o $@ $(FLAGS) srcs/libfill.a libft/libft.a

clean :
	@$(MAKE) -C srcs/ clean
	@$(MAKE) -C libft/ clean
	@rm -f $(OBJS)

fclean : clean
	@$(MAKE) -C srcs/ fclean
	@$(MAKE) -C libft/ fclean
	@rm -rf $(NAME) libfill.a

re : fclean all
