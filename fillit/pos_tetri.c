/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 19:52:00 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/06 18:09:08 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "./libft/libft.h"
#include "ft_prog.h"

int		pos_tetri(t_forme **ptr_lst, char **tab, int xt, int yt, int sizey, int sizex)
{
	t_forme	*p;
	int		yl;
	int		xl;
	int		countx = 0, county = 0, countp = 0;
	char	c;
	char **ptab;

	p = *ptr_lst;
	ptab = p->next->tab;
	c = p->next->myletter;
	yl = p->next->yaxis;
	xl = p->next->xaxis;
	while (tab[yt] && tab[yt][xt] == '.')
	{
		while (ptab[yl] && yt + county < sizey)
		{
			while (ptab[yl][xl] && ptab[yl][xl] == '#' && xt + countx < sizex)
			{
				return (0);

			}
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
