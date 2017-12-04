/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 19:52:00 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/04 20:33:32 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlin.h>
#include <stdio.h>
#include "./libft/libft.h"
#include "ft_prog.h"



char		**pos_tetri(t_forme **ptr_lst, char **tab, int xaxe, int yaxe)
{
	t_forme	*p;
	int		y;
	int		x;
	char	c;

	p = *ptr_lst;
	c = p->next->myletter;
	y = p->next->yaxis;
	x = p->next->xaxis;
	if (tab[yaxe][xaxe] != '.')
		xaxe++;
	if (tab[yaxe][xaxe] == '.')
	{
		while (p->next->tab[y])
		{
			while (p->next->tab[y][x] && p->next->tab[y][x] != c)
			{
				x++;
			}
			if (p->next->tab[y][x] && p->next->tab[y][x] == c)
			{
				tab[yaxe + y][xaxe + x] == p->next->tab[y][x];
				x++;
			}
			if (!p->next->tab[y][x])
			{
				x = 0;
				y++;
			}
		}
	}
}
