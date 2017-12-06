/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 19:52:00 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/06 19:11:00 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "./libft/libft.h"
#include "ft_prog.h"

t_coor	check_pos_possible(t_forme *ptr)
{
	t_coor	*x_chk;
	t_coor	*y_chk;
	t_coor	offset;

	x_chk = tab_x_search(ptr);
	y_chk = tab_y_search(ptr);
	offset.y = 0;
	offset.x = 0;
	if (x_chk->y < y_chk->y)
	{
		offset.y = y_chk->y - x_chk->y;
		offset.x = x_chk->x - y_chk->x;
	}
	return (offset);
}

int		pos_tetri(t_forme **ptr_lst, char **tab, int xt, int yt, t_coor offset)
{
	t_forme	*p;
	int		yl;
	int		xl;
	int		countx = 0, county = 0, countp = 0, size = ft_strlen(*tab);
	char	c;
	char **ptab;

	p = *ptr_lst;
	ptab = p->next->tab;
	c = p->next->myletter;
	yl = p->next->yaxis;
	xl = p->next->xaxis;
	while (tab[yt] && tab[yt][xt] == '.')
	{
		while (ptab[yl])
		{
			if (yt + county > size)
				return (1);
			while (ptab[yl][xl] && ptab[yl][xl] == c)
			{
				if (xt + countx > size)
					return (1);
				tab[yt][xt + offset.x] = ptab[yl][xl];
				xl++;
				xt++;
				if (offset.x > 0)
					offset.y--;
				countx++;
			}
			if (offset.y == 0)
				offset.x = 0;
			xl = 0;
			yl++;
		}
	}
		if (countp != 4)
			return (1);
	return (0);
}

/*char		**backtrack_debut(t_forme **ptr_lst, int sizex, int sizey)
{
	char **tab;
	t_forme **ptr;

	ptr = ptr_lst;
	tab = ft_newtab(sizey, sizex, '.');
	if (!(*ptr_lst)->next)
		return (tab);
	while ((*ptr_lst)->next->tab && (*ptr_lst)->next->tab == '.')
	{
			if (place piece function == 1)
				send new first coordonate to place piece;
	}
	if (piece placed)
		backtrack_debut(ptr_lst + 1, sizex, sizey);
	return (tab);
}*/
