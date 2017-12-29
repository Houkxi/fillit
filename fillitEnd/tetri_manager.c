/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:22:39 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/29 16:56:16 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "./libft/libft.h"
#include "ft_prog.h"

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
	if (nbr_tetri == 1)
		return (2);
	if (nbr_tetri == 2)
		return (3);
	if (nbr_tetri > 2 && nbr_tetri <= 5)
		return (4);
	if (nbr_tetri > 5 && nbr_tetri < 10)
		return (6);
	if (nbr_tetri > 9 && nbr_tetri < 17)
		return (8);
	if (nbr_tetri > 16 && nbr_tetri < 26)
		return (10);
	if (nbr_tetri >= 26)
		return (12);
	return (0);
}
