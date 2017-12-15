# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 07:31:59 by mmanley           #+#    #+#              #
#    Updated: 2017/12/15 14:10:57 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exe

CC = gcc -o

FLAGS = -Wall -Wextra -Werror

#HCFLAG = -fsanitize=adress

INC = libft/libft.h

SRCS = 	main.c\
		backtrack_rec.c\
		file_lexing_parsing.c\
		ft_lstnew_re.c\
		tetri_check.c\
		ft_lstadd_end.c\
		ft_lst_print.c\
		ft_lstmapi_f.c\
		pos_and_check.c\
		./not_finished/tab_resize.c\
		./not_finished/ft_tab_searcher.c\

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
