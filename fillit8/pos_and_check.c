/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_and_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:52:06 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/26 15:53:40 by mmanley          ###   ########.fr       */
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

int			pos_ok(int y, int x, t_coor lco, char **newt)
{
	int size;

	size = ft_strlen(newt[0]);
	lco.y2 += y;
	lco.x2 += x;
	if (lco.y2 < 0 || lco.x2 < 0 || lco.y2 >= size
	|| lco.x2 >= size || newt[lco.y2][lco.x2] != '.')
		return (0);
	else
		return (1);
}

int			check_posabilty(t_forme *ptr, int pos, int size, char **newt)
{
	t_coor	lco;
	char	**tab;

	tab = ptr->tab;
	lco.y2 = pos / size;
	lco.x2 = pos % size;
	lco.y1 = 0;
	lco.y3 = 1;
	if (newt[lco.y2][lco.x2] != '.')
		return (0);
	if (lco.y1 == 0)
	{
		lco.y1 += pos_ok(ptr->cmps->y1, ptr->cmps->x1, lco, newt);
	}
	if (lco.y1 == 1)
	{
		lco.y1 += pos_ok(ptr->cmps->y2, ptr->cmps->x2, lco, newt);
	}
	if (lco.y1 == 2)
	{
		lco.y1 += pos_ok(ptr->cmps->y3, ptr->cmps->x3, lco, newt);
	}
	if (lco.y1 == 3)
		return (1);
	return (0);
}
