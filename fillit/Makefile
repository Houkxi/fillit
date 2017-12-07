# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 07:31:59 by mmanley           #+#    #+#              #
#    Updated: 2017/12/07 12:31:10 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exe

CC = gcc -o

FLAGS = -Wall -Wextra -Werror

#HCFLAG = -fsanitize=adress

INC = libft/libft.h

SRCS = 	main.c\
		file_lexing_parsing.c\
		ft_lstnew_re.c\
		file_lexing.c\
		ft_lstadd_end.c\
		ft_lst_print.c\
		ft_pos_tetri.c\
		./not_finished/tab_resize.c\
		ft_tab_searcher.c\
		ft_lstmapi_f.c\
		./not_finished/ft_lstdel_f.c\

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	$(CC) $@ $(FLAGS) $(SRCS) libft/libft.a -I $(INC)

sub :
	cd libft && make re

subclean :
	cd libft && make clean

subre :
	cd libft && make fclean && make all

clean :
	@rm -f $(OBJS)

fclean :
	@rm -rf $(NAME)

re : fclean all
