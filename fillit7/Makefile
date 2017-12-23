# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 07:31:59 by mmanley           #+#    #+#              #
#    Updated: 2017/12/23 17:12:31 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

FLAGS = -Wall -Wextra -Werror

INC = libft/libft.h

SRCS = 	main.c\
		backtrack_rec.c\
		file_lexing_parsing.c\
		ft_lstnew_re.c\
		tetri_manager.c\
		ft_lstadd_end.c\
		ft_lstdel_f.c\
		ft_lst_print.c\
		ft_lstmapi_f.c\
		pos_and_check.c\

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	cd libft && make re
	$(CC) -c $(FLAGS) $(SRCS) -I $(INC)
	ar rc libfill.a $(OBJS)
	$(CC) -o $@ $(FLAGS) libfill.a libft/libft.a

sub :
	cd libft && make re

subclean :
	cd libft && make clean

subre :
	cd libft && make fclean && make all

debug :
	cd libft && make re
	$(CC) -c $(FLAGS) $(SRCS) -I $(INC)
	ar rc libfill.a $(OBJS)
	$(CC) -g -o $(NAME) $(FLAGS) libfill.a libft/libft.a

clean :
	cd libft && make clean
	@rm -f $(OBJS)

fclean : clean
	cd libft && make fclean
	@rm -rf $(NAME) libfill.a

re : fclean all
