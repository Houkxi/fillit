/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 19:52:00 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/11 12:27:54 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "./libft/libft.h"
#include "ft_prog.h"

/*t_coor	check_pos_possible(t_forme *ptr)
{
	t_coor	*x_chk;
	t_coor	*y_chk;
	t_coor	offset;
	t_forme *p;

	p = ptr;
	x_chk = tab_x_search(p);
	p = ptr;
	y_chk = tab_y_search(p);
	printf("Y (%u, %u), X (%u, %u)\n", y_chk->y, y_chk->x, x_chk->y, x_chk->x);
	offset.y = 0;
	offset.x = 0;
	if (x_chk->y < y_chk->y)
	{
		offset.y = y_chk->y - x_chk->y;
		offset.x = x_chk->x - y_chk->x;
	}
	free(x_chk);
	free(y_chk);
	//FREE CHECK//printf("Y (%u, %u), X (%u, %u)\n", y_chk->y, y_chk->x, x_chk->y, x_chk->x);
	printf("Offset (%u, %u)\n", offset.y, offset.x);
	return (offset);
}*/

b_coor	*check_pos_possible(t_forme *ptr, b_coor *new_ptv)
{
	new_ptv->sec_elem.x -= ptr->next->xaxis;
	new_ptv->sec_elem.y -= ptr->next->yaxis;
	new_ptv->third_elem.x -= ptr->next->xaxis;
	new_ptv->third_elem.y -= ptr->next->yaxis;
	new_ptv->fourth_elem.x -= ptr->next->xaxis;
	new_ptv->fourth_elem.y -= ptr->next->yaxis;
	return (new_ptv);
}

char		**pos_tetri(t_forme **ptr_lst, char **tab, int xt, int yt, b_coor *offset, int tabsize)
{
	int piece_nbr;

	piece_nbr = 0;
	printf("TEST\n");
	if (tab)
	{
		printf("%d\n", yt);
		if (tab[yt][xt] && tab[yt][xt] == '.')
		{
			tab[yt][xt] = (*ptr_lst)->next->tab[(*ptr_lst)->next->yaxis][(*ptr_lst)->next->xaxis];
			printf("%s\n", tab[yt]);
			piece_nbr++;
		}
		printf("Y = %d, X = %d\n", (yt + offset->sec_elem.y), (xt + offset->sec_elem.x));
		if (tab[yt][xt] && (yt + offset->sec_elem.y) >= 0 &&
			(yt + offset->sec_elem.y) < tabsize && (xt + offset->sec_elem.x) >= 0
			&& (xt + offset->sec_elem.x) < tabsize)
		{
			tab[yt + offset->sec_elem.y][xt + offset->sec_elem.x] = 'A';
			printf("%s\n", tab[yt + offset->sec_elem.y]);
			piece_nbr++;
		}
		printf("Y = %d, X = %d\n", (yt + offset->third_elem.y), (xt + offset->third_elem.x));
		if (tab[yt][xt] && (yt + offset->third_elem.y) >= 0 &&
			(yt + offset->third_elem.y) < tabsize && (xt + offset->third_elem.x) >= 0
			&& (xt + offset->third_elem.x) < tabsize)
		{
			tab[yt + offset->third_elem.y][xt + offset->third_elem.x] = 'A';
			printf("%s\n", tab[yt + offset->third_elem.y]);
			piece_nbr++;
		}
		printf("Y = %d, X = %d\n", (yt + offset->fourth_elem.y), (xt + offset->fourth_elem.x));
		if (tab[yt][xt] && (yt + offset->fourth_elem.y) >= 0 &&
			(yt + offset->fourth_elem.y) < tabsize && (xt + offset->fourth_elem.x) >= 0
			&& (xt + offset->fourth_elem.x) < tabsize)
		{
			tab[yt + offset->fourth_elem.y][xt + offset->fourth_elem.x] = 'A';
			printf("%s\n\n", tab[yt + offset->fourth_elem.y]);
			piece_nbr++;
		}
		if (piece_nbr == 4)
			return (tab);
		else
			return (NULL);
	}
	return (NULL);
}

/*char		**pos_tetri(t_forme **ptr_lst, char **tab, int xt, int yt, t_coor offset)
{
	t_forme	*p;
	int		yl;
	int		xl;
	int		countx = 0, county = 0, size = ft_strlen(*tab);
	char	c;
	char **ptab;

	p = *ptr_lst;
	ptab = p->next->tab;
	c = p->next->myletter;
	yl = p->next->yaxis;
	xl = p->next->xaxis;
	printf("Yo J'Y SUIS, %d\n", size);
	if (tab[yt] && tab[yt][xt] == '.')
	{
		while (ptab[yl])
		{
			printf("Yt = %d, Xt = %d // Yl = %d, Xl = %d\n", yt, xt, yl, xl);
			if (yt + county > size)
			{
				printf("Y Size to > %d + %d\n", yt, county);
				return (NULL);
			}
			while (ptab[yl][xl] && ptab[yl][xl] != c)
				xl++;
			while (ptab[yl][xl] && ptab[yl][xl] == c)
			{
				printf("%d\n", xt);
				if (xt + countx > size)
				{
					printf("X Size to >\n");
					return (NULL);
				}
				tab[yt][xt + offset.x] = ptab[yl][xl];
				xl++;
				xt++;
				if (offset.x > 0 && offset.y > 0)
					offset.y--;
				countx++;
			}
			printf("OffY = %d, OffX = %d\n", offset.y, offset.x);
			if (offset.y == 0)
				offset.x = 0;
			xl = 0;
			xt = 0;
			yl++;
			yt++;
		}
	}
		if (countp != 4)
		{
			printf("What Size to >\n");
			return (NULL);
		}
	//printf("%s\n", ptab[1]);
	return (tab);
}*/

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
