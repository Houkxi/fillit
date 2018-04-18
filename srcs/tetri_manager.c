/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:22:39 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/18 17:07:02 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include "fillit.h"

int			ft_sqr_root(int nb)
{
	int sqr;

	sqr = 0;
	while (sqr * sqr < nb)
		sqr++;
	return (sqr);
}

int			check_tetri(char *str, int start)
{
	int		adj;

	adj = 0;
	while (str[start])
	{
		if (str[start] && str[start] == '#')
		{
			if (str[start + 1] == '#')
				adj++;
			if (str[start - 1] == '#')
				adj++;
			if (str[start + 5] == '#')
				adj++;
			if (str[start - 5] == '#')
				adj++;
			start++;
		}
		else
			start++;
	}
	if (adj == 6 || adj == 8)
		return (1);
	else
		return (0);
}

void		pos_tetriminos(t_forme *pt, char **newt, int pos, int size)
{
	t_coor	co;

	co = struct_cre(pos, size);
	while (pt->tab[co.y])
	{
		while (pt->tab[co.y][co.x] && pt->tab[co.y][co.x] != pt->myl)
			co.x++;
		while (pt->tab[co.y][co.x] && pt->tab[co.y][co.x] == pt->myl)
		{
			co.a1 += (int)(co.x - (int)pt->xaxis);
			newt[co.b1][co.a1] = pt->tab[co.y][co.x];
			if (co.a1 != pos % size)
				co.a1 = pos % size;
			co.x++;
			co.i++;
		}
		if (co.i != 0)
			co.b1++;
		co.x = 0;
		co.i = 0;
		co.y++;
	}
}

int			optimal_tab_size(int nbr_tetri)
{
	int res;

	res = ft_sqr_root(nbr_tetri * 4);
	return (res);
}
