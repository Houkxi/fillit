/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:22:39 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/26 15:32:19 by mmanley          ###   ########.fr       */
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
	int		y;
	int		x;
	int		i;

	y = 0;
	x = 0;
	co.y = pos / size;
	co.x = pos % size;
	i = 0;
	while (pt->tab[y])
	{
		while (pt->tab[y][x] && pt->tab[y][x] != pt->myl)
			x++;
		while (pt->tab[y][x] && pt->tab[y][x] == pt->myl)
		{
			co.x += (int)(x - (int)pt->xaxis);
			newt[co.y][co.x] = pt->tab[y][x];
			if (co.x != pos % size)
				co.x = pos % size;
			x++;
			i++;
		}
		if (i != 0)
			co.y++;
		x = 0;
		i = 0;
		y++;
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
