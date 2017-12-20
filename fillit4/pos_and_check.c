/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_and_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:52:06 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/20 11:50:34 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "./libft/libft.h"
#include "ft_prog.h"

int			tab_checker(t_forme *ptr, char **tab)
{
	int		y;
	int		x;
	int		stck;

	y = 0;
	x = 0;
	stck = ft_strlen(tab[0]);
	while (tab[y])
	{
		while (tab[y][x] && tab[y][x] != ptr->next->myl)
			x++;
		if (tab[y][x] && tab[y][x] == ptr->next->myl)
		{
			if (y == 0)
				return (x);
			else
				return ((x) + (y * stck));
		}
		x = 0;
		y++;
	}
	return (-1);
}

void		tab_corrector(t_forme *ptr, char **tab)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (tab[y])
	{
		while (tab[y][x] && tab[y][x] != ptr->next->myl)
			x++;
		while (tab[y][x] && tab[y][x] == ptr->next->myl)
		{
			tab[y][x] = '.';
			x++;
		}
		x = 0;
		y++;
	}
}

int			chk_all_psblty(t_forme *ptr, int size, int pos, char **newt)
{
	int i;
	char **tab;

	tab = newt;
	tab_corrector(ptr, tab);
	i = tab_checker(ptr, tab);
	pos = i;
	while (i < size * size - 1)
	{
		if (ptr->next && (check_posabilty(ptr, i, ptr->next->tab, newt)) == 1)
			return (1);
		i++;
	}
	return (0);
}

int			check_posabilty(t_forme *ptr, int pos, char **tab, char **newt)
{
	t_coor	lco;
	t_coor	t_co;
	int		i;
	int		j;

	lco.y = 0;
	lco.x = 0;
	i = ft_strlen(newt[0]);
	j = 0;
	t_co.y = pos / i;
	t_co.x = pos % i;
	while (tab[lco.y])
	{
		while (tab[lco.y][lco.x] && tab[lco.y][lco.x] != ptr->next->myl)
			lco.x += 1;
		while (tab[lco.y][lco.x] && tab[lco.y][lco.x] == ptr->next->myl)
		{
			t_co.y += (lco.y - ptr->next->yaxis);
			t_co.x += (lco.x - ptr->next->xaxis);
			if (t_co.y < 0 || t_co.x < 0 || t_co.y >= i
			|| t_co.x >= i || newt[t_co.y][t_co.x] != '.')
				return (0);
			j++;
			t_co.y = pos / i;
			t_co.x = pos % i;
			lco.x += 1;
		}
		lco.y += 1;
		lco.x = 0;
	}
	if (j == 4)
		return (1);
	return (0);
}

int			pos_tetriminos(t_forme *pt, char **newt, int pos, int size)
{
	t_coor	co;
	int		y;
	int		tmp;
	int		x;
	int		i;

	y = 0;
	x = 0;
	co.y = pos / size;
	co.x = pos % size;
	i = 0;
	tmp = co.x;
		while (pt->next->tab[y])
		{
			while (pt->next->tab[y][x] && pt->next->tab[y][x] != pt->next->myl)
				x++;
			while (pt->next->tab[y][x] && pt->next->tab[y][x] == pt->next->myl)
			{
				co.x += (int)(x - (int)pt->next->xaxis);
				newt[co.y][co.x] = pt->next->tab[y][x];
				if (co.x != tmp)
					co.x = tmp;
				x++;
				i++;
			}
			if (i != 0)
			{
				co.y++;
			}
			x = 0;
			i = 0;
			y++;
		}
	return (0);
}
