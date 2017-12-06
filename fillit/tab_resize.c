/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:24:13 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/06 17:28:09 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "./libft/libft.h"
#include "ft_prog.h"

int		tab_x_size(char **tab)
{
	int stck;
	int x;
	int y;
	int xcount;
	int ycount;

	stck = 0;
	x = 0;
	y = 0;
	xcount = 0;
	ycount = 0;
	if (tab)
	{
		while (tab[y])
		{
			while (tab[y][x] && tab[y][x] != '#')
				x++;
			while (tab[y][x] && tab[y][x] == '#')
			{
				//printf("Xcount\n" );
				xcount++;
				ycount = y;
				x++;
			}
			if (stck < xcount)
				stck = xcount;
			xcount = 0;
			x = 0;
			y++;
		}
		//printf("END LINE = %d___%d\n", ycount, stck);
	}
	return (stck);
}

int		tab_y_size(char **tab)
{
	int x;
	int y;
	int xcount;
	int ycount;

	x = 0;
	y = 0;
	xcount = 0;
	ycount = 0;
	if (tab)
	{
		while (tab[y][x])
		{
			while (tab[y] && tab[y][x] != '#')
				y++;
			while (tab[y] && tab[y][x] == '#')
			{
				//printf("Xcount\n" );
				ycount++;
				xcount = x;
				y++;
			}
			ycount = 0;
			y = 0;
			x++;
		}
		//printf("END COL = %d___%d\n", xcount, stck);
	}
	return (xcount);
}

/*char	**tab_resize(char **tab, int y, int y)
{
	char **newtab;
	int newy;
	int newx;

	newtab = ft_newtab(y, x, '.');
	while (tab[y] || newtab[newy])
	{
		while (tab[y][x] && tab[y][x] == '#')
		{
			newtab[newy][newx] ==
		}
	}
}*/
