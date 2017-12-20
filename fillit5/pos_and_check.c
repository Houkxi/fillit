/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_and_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:52:06 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/20 16:02:55 by mmanley          ###   ########.fr       */
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
		while (tab[lco.y][lco.x] && tab[lco.y][lco.x] != ptr->myl)
			lco.x += 1;
		while (tab[lco.y][lco.x] && tab[lco.y][lco.x] == ptr->myl)
		{
			t_co.y += (lco.y - ptr->yaxis);
			t_co.x += (lco.x - ptr->xaxis);
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
