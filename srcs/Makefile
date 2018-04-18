# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 18:54:36 by mmanley           #+#    #+#              #
#    Updated: 2018/01/18 10:41:25 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfill.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

INC = ../libft/

SRCS =	main.c\
		backtrack_rec.c\
		file_lexing_parsing.c\
		ft_lstnew_re.c\
		tetri_manager.c\
		ft_lstadd_end.c\
		ft_lstdel_f.c\
		ft_lstmapi_f.c\
		pos_and_check.c\
		ft_lst_print.c\

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) -c $(FLAGS) $(SRCS) -I $(INC)

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
