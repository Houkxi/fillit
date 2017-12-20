/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:08:46 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/20 11:52:21 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
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
	return (0);
}

int			check_manager(char *str)
{
	t_forme **ptr_lst;
	int size;
	int i;
	int endsize;
	int pos;
	char	**tab;

	ptr_lst = (t_forme**)malloc(sizeof(t_forme*));
	*ptr_lst = ft_lstnew_re(NULL, 0);
	size = 2;
	i = 0;
	pos = 0;
	endsize = 0;
	tab = ft_newtab(2, 2, '.');
	if ((square_checks(str, 0, 0, ptr_lst)) == 0)
	{
		free(ptr_lst);
		write(1, "error\n", 6);
		return (0);
	}
	final_parsing(ptr_lst);
	while (endsize != -1)
	{
		free(tab);
		tab = ft_newtab(size, size, '.');
		if((endsize = backy_tracky(tab, ptr_lst, pos, size)) == 0)
			size++;
	}
	ft_show_tab(tab);
	return (1);
}

int			main(int argv, char **argc)
{
	int		fd;
	int		ret;
	char	pretab[1024];

	if (argv == 2)
	{
		if ((fd = open(argc[1], O_RDONLY)) == -1)
			return (0);
		if ((ret = read(fd, pretab, 1024)) == -1)
			return (0);
		if ((check_manager(pretab)) == 0)
			return (0);
	}
	if (argv != 2)
	{
		write(1,"cp ___source_file target_file\n", 30);
	}
	return (0);
}
