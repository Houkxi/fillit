/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:08:46 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/06 16:29:04 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "./libft/libft.h"
#include "ft_prog.h"

int			final_parsing(t_forme **ptr_lst)
{
	t_forme *ptr;

	ptr = *ptr_lst;
	ptr = ft_lstmapi(ptr, &coor_search, 0);
	ptr = *ptr_lst;
	ptr = ft_lstmapi(ptr, &alpha_swap, 0);
	ft_lst_print(ptr_lst);
	return (0);
}

int			check_manager(char *str, int choose)
{
	t_forme **ptr_lst;

	ptr_lst = (t_forme**)malloc(sizeof(t_forme*));
	*ptr_lst = ft_lstnew_re(NULL, 0);
	if (choose == 1)
	{
		if ((square_checks(str, 0, 0, ptr_lst)) == 0)
		{
			free(ptr_lst);
			printf("\nNOT valid file !!\n");
			return (0);
		}
		final_parsing(ptr_lst);
		//backtrack_debut(ptr_lst);
	}
	if (choose == 2)
	{
		if ((square_checker(str, 0, 0, 0)) == 0)
		{
			printf("\nNOT valid file !!\n");
			return (0);
		}
	}
	return (1);
}

int			main(int argv, char **argc)
{
	int		fd;
	int		ret;
	int		av;
	char	pretab[1024];

	if (argv == 3)
	{
		if ((fd = open(argc[2], O_RDONLY)) == -1)
			return (0);
		if ((ret = read(fd, pretab, 1024)) == -1)
			return (0);
		av = ft_atoi(argc[1]);
		if ((check_manager(pretab, av)) == 0)
			return (0);
	}
	if (argv != 3)
	{
		printf("cp ___source_file target_file\n");
	}
	return (0);
}
