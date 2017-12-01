# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 07:31:59 by mmanley           #+#    #+#              #
#    Updated: 2017/12/01 16:46:53 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exe

CC = gcc -o

FLAGS = -Wall -Wextra -Werror

#HCFLAG = -fsanitize=adress

INC = ./libft/libft.h

SRCS = ./tests.c ./file_checker.c ./ft_lstnew_re.c ./ft_tabcpy.c ./checking.c\
		./ft_lstadd_end.c\

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	$(CC) $@ $(FLAGS) $(SRCS) ./libft/libft.a -I $(INC)

sub :
	cd libft && make re && make clean

clean :
	@rm -f $(OBJS)

fclean :
	@rm -rf $(NAME)

re : fclean all
