/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:08:46 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/07 15:10:36 by mmanley          ###   ########.fr       */
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
	ptr = ft_lstmapi_f(ptr, &coor_search, 0);
	ptr = *ptr_lst;
	ptr = ft_lstmapi_f(ptr, &alpha_swap, 0);
	ft_lst_print(ptr_lst);
	return (0);
}

int			check_manager(char *str, int choose)
{
	t_forme **ptr_lst;
	t_forme *ptr;
	char	**tab;
	t_coor	offset;
	t_coor	*newcoor;;
	b_coor	*all_coor;

	ptr_lst = (t_forme**)malloc(sizeof(t_forme*));
	*ptr_lst = ft_lstnew_re(NULL, 0);
	all_coor = (b_coor*)malloc(sizeof(b_coor));
	newcoor = (t_coor*)malloc(sizeof(newcoor));
	newcoor->y = 0;
	newcoor->x = 0;
	all_coor->sec_elem = *newcoor;
	all_coor->third_elem = *newcoor;
	all_coor->fourth_elem = *newcoor;
	tab = ft_newtab(4, 4, '.');
	if (choose == 1)
	{
		if ((square_checks(str, 0, 0, ptr_lst)) == 0)
		{
			free(ptr_lst);
			printf("\nNOT valid file !!\n");
			return (0);
		}
		final_parsing(ptr_lst);
		ptr = *ptr_lst;
		offset = check_pos_possible(ptr);
		ptr = *ptr_lst;
		printf("\n\n\n");
		ft_all_pos(ptr, all_coor);
		printf("_____________________(%d, %d)\n", all_coor->sec_elem.x, all_coor->sec_elem.y);
		printf("_____________________(%d, %d)\n", all_coor->third_elem.x, all_coor->third_elem.y);
		printf("_____________________(%d, %d)\n\n\n", all_coor->fourth_elem.x, all_coor->fourth_elem.x);
		if ((tab = pos_tetri(ptr_lst, tab, 0, 0, offset)) == NULL)
		{
			printf("RATER\n");
			return(0);
		}
		ft_show_tab(tab);
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
