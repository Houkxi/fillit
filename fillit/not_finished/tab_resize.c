/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:24:13 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/07 12:31:49 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "../ft_prog.h"

int		tab_x_size(char **tab)
{
	int stck;
	int x;
	int y;
	int xcount;

	stck = 0;
	x = 0;
	y = 0;
	xcount = 0;
	if (tab)
	{
		while (tab[y])
		{
			while (tab[y][x] && tab[y][x] != '#')
				x++;
			while (tab[y][x] && tab[y][x] == '#')
			{
				xcount++;
				x++;
			}
			if (stck < xcount)
				stck = xcount;
			xcount = 0;
			x = 0;
			y++;
		}
	}
	return (stck);
}

int		tab_y_size(char **tab)
{
	int x;
	int y;
	int ycount;

	x = 0;
	y = 0;
	ycount = 0;
	if (tab)
	{
		while (tab[y][x])
		{
			while (tab[y] && tab[y][x] != '#')
				y++;
			while (tab[y] && tab[y][x] == '#')
			{
				ycount = x;
				y++;
			}
			y = 0;
			x++;
		}
	}
	return (ycount);
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
