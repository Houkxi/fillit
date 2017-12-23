/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_and_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:52:06 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/23 18:39:26 by mmanley          ###   ########.fr       */
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

int			check_posabilty(t_forme *ptr, int pos, int i, char **newt)
{
	t_coor	lco;
	char	**tab;

	tab = ptr->tab;
	lco.y2 = pos / i;
	lco.x2 = pos % i;
	lco.y1 = 0;
	lco.y3 = 1;
	if (newt[lco.y2][lco.x2] != '.')
		return (0);
	while (lco.y1 < 3)
	{
		if (lco.y1 == 0)
		{
			lco.y2 += ptr->cmps->y1;
			lco.x2 += ptr->cmps->x1;
			lco.y3++;
		}
		if (lco.y1 == 1)
		{
			lco.y2 += ptr->cmps->y2;
			lco.x2 += ptr->cmps->x2;
			lco.y3++;
		}
		if (lco.y1 == 2)
		{
			lco.y2 += ptr->cmps->y3;
			lco.x2 += ptr->cmps->x3;
			lco.y3++;
		}
		if (lco.y2 < 0 || lco.x2 < 0 || lco.y2 >= i
		|| lco.x2 >= i || newt[lco.y2][lco.x2] != '.')
			return (0);
		lco.y2 = pos / i;
		lco.x2 = pos % i;
		lco.y1 += 1;
	}

	if (lco.y3 == 4)
		return (1);
	return (0);
}

/*
int			check_posabilty(t_forme *ptr, int pos, int i, char **newt)
{
	t_coor	lco;
	char	**tab;

	lco.y1 = 0;
	lco.x1 = 0;
	tab = ptr->tab;
	lco.y3 = 0;
	lco.y2 = pos / i;
	lco.x2 = pos % i;
	while (tab[lco.y1])
	{
		while (tab[lco.y1][lco.x1] && tab[lco.y1][lco.x1] != ptr->myl)
			lco.x1 += 1;
		while (tab[lco.y1][lco.x1] && tab[lco.y1][lco.x1] == ptr->myl)
		{
			lco.y2 += (lco.y1 - ptr->yaxis);
			lco.x2 += (lco.x1 - ptr->xaxis);
			if (lco.y2 < 0 || lco.x2 < 0 || lco.y2 >= i
			|| lco.x2 >= i || newt[lco.y2][lco.x2] != '.')
				return (0);
			lco.y3++;
			lco.y2 = pos / i;
			lco.x2 = pos % i;
			lco.x1 += 1;
		}
		lco.y1 += 1;
		lco.x1 = 0;
	}
	if (lco.y3 == 4)
		return (1);
	return (0);
}
*/
