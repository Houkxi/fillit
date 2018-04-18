/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_and_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:52:06 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/18 13:41:59 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include "fillit.h"

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
		while (tab[y][x] && tab[y][x] != ptr->myl)
			x++;
		if (tab[y][x] && tab[y][x] == ptr->myl)
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
		while (tab[y][x] && tab[y][x] != ptr->myl)
			x++;
		while (tab[y][x] && tab[y][x] == ptr->myl)
		{
			tab[y][x] = '.';
			x++;
		}
		x = 0;
		y++;
	}
}

t_coor		struct_cre(int pos, int size)
{
	t_coor co;

	co.y = 0;
	co.x = 0;
	co.a1 = pos % size;
	co.b1 = pos / size;
	co.i = 0;
	return (co);
}

int			check_posabilty(t_forme *p, int pos, int i, char **newt)
{
	t_coor	lco;

	lco = struct_cre(pos, i);
	while (p->tab[lco.y])
	{
		while (p->tab[lco.y][lco.x] && p->tab[lco.y][lco.x] != p->myl)
			lco.x += 1;
		while (p->tab[lco.y][lco.x] && p->tab[lco.y][lco.x] == p->myl)
		{
			lco.b1 += (lco.y - p->yaxis);
			lco.a1 += (lco.x - p->xaxis);
			if (lco.b1 < 0 || lco.a1 < 0 || lco.b1 >= i
			|| lco.a1 >= i || newt[lco.b1][lco.a1] != '.')
				return (0);
			lco.i++;
			lco.b1 = pos / i;
			lco.a1 = pos % i;
			lco.x += 1;
		}
		lco.y += 1;
		lco.x = 0;
	}
	if (lco.i == 4)
		return (1);
	return (0);
}
