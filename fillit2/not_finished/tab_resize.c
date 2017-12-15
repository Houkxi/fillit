/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:24:13 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/14 12:03:45 by mmanley          ###   ########.fr       */
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
			while (tab[y][x] && tab[y][x] == '.')
				x++;
			if (tab[y][x] && tab[y][x] != '.')
			{
				xcount++;
				while (tab[y][x] && tab[y][x] != '.')
					x++;
			}
			x = 0;
			y++;
		}
	}
	return (xcount);
}
///////IL EST FAUX////////////
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
			while (tab[y] && tab[y][x] == '.')
				y++;
			if (tab[y] && tab[y][x] != '.')
			{
				ycount++;
				while (tab[y] && tab[y][x] != '.')
					y++;
			}
			y = 0;
			x++;
		}
	}
	return (ycount);
}

int		dot_x_size(char **tab)
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
			while (tab[y][x] && tab[y][x] != '.')
				x++;
			while (tab[y][x] && tab[y][x] == '.')
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
///////IL EST FAUX////////////
int		dot_y_size(char **tab)
{
	int x;
	int y;
	int ycount;
	int stck;

	x = 0;
	y = 0;
	ycount = 0;
	stck = 0;
	if (tab)
	{
		while (tab [y] && tab[y][x])
		{
			while (tab[y] && tab[y][x] != '.')
				y++;
			while (tab[y] && tab[y][x] == '.')
			{
				ycount++;
				y++;
			}
			if (stck < ycount)
				stck = ycount;
			ycount = 0;
			y = 0;
			x++;
		}
	}
	return (stck);
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
