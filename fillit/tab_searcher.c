/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_searcher.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:24:13 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/06 19:11:47 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "./libft/libft.h"
#include "ft_prog.h"

t_coor	*tab_x_search(t_forme *elem)
{
	int stck;
	unsigned int x;
	unsigned int y;
	int xcount;
	int ycount;
	char **tab;
	t_coor *coor_hor = NULL;

	stck = 0;
	x = 0;
	y = 0;
	xcount = 0;
	ycount = 0;
	tab = elem->next->tab;
	if (elem->next)
	{
		while (tab[y])
		{
			while (tab[y][x] && tab[y][x] != '#')
				x++;
			if (tab[y][x] && tab[y][x] == '#')
			{
				coor_hor->y = y;
				coor_hor->x = x;
				return (coor_hor);
			}
			if (stck < xcount)
				stck = xcount;
			xcount = 0;
			x = 0;
			y++;
		}
		//printf("END LINE = %d___%d\n", ycount, stck);
	}
	return (coor_hor);
}

t_coor	*tab_y_search(t_forme *elem)
{
	unsigned int x;
	unsigned int y;
	int xcount;
	int ycount;
	char **tab;
	t_coor *coor_ver = NULL;

	x = 0;
	y = 0;
	xcount = 0;
	ycount = 0;
	tab = elem->next->tab;
	if (elem->next)
	{
		while (tab[y][x])
		{
			while (tab[y] && tab[y][x] != '#')
				y++;
			if (tab[y] && tab[y][x] == '#')
			{
				coor_ver->y = y;
				coor_ver->x = x;
				return (coor_ver);
			}
			ycount = 0;
			y = 0;
			x++;
		}
	}
	return (coor_ver);
}
