/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:08:46 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/22 15:08:28 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "fillit.h"

static int	lst_count(t_forme *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

static int	final_parsing(t_forme *ptr_lst, int *minsize)
{
	t_forme *ptr;

	ptr = ptr_lst;
	ptr = ft_lstmapi_f(ptr, &coor_search, 0);
	ptr = ptr_lst;
	ptr = ft_lstmapi_f(ptr, &alpha_swap, 0);
	ptr = ptr_lst;
	*minsize = lst_count(ptr_lst);
	return (0);
}

static int	check_manager(char *s, int size, int end, int minsize)
{
	char	**tab;
	t_forme *ptr_lst;

	tab = NULL;
	ptr_lst = NULL;
	if ((square_checks(s, 0, 0, &ptr_lst)) == 0)
	{
		free(ptr_lst);
		write(1, "error\n", 6);
		return (0);
	}
	final_parsing(ptr_lst, &minsize);
	size = optimal_tab_size(minsize);
	while (end != -1)
	{
		free(tab);
		tab = ft_newtab(size, size, '.');
		if ((end = backy_tracky(tab, ptr_lst, size, 0)) == 0)
			size++;
	}
	ft_lstmapi_f(ptr_lst, &ft_lstdel_f, 0);
	ft_show_tab(tab);
	ft_deltab(tab);
	tab = NULL;
	return (1);
}

int			main(int argv, char **argc)
{
	int		fd;
	int		ret;
	char	pretab[2048];

	if (argv == 2)
	{
		if ((fd = open(argc[1], O_RDONLY)) == -1)
		{
			write(1, "error\n", 6);
			return (0);
		}
		if ((ret = read(fd, pretab, 2048)) == -1)
			return (0);
		if ((check_manager(pretab, 2, 0, 1)) == 0)
			return (0);
	}
	if (argv != 2)
		write(1, "usage : ./fillit [File contains up to 26 tetriminos]\n", 55);
	return (0);
}
