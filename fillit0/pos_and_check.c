/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_and_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:52:06 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/11 18:41:32 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./libft/libft.h"
#include "ft_prog.h"

int		check_pos(t_forme *ptr, t_coor co, char **tab, char **newtab)
{
	t_coor lco;
	t_coor t_co;

	lco.y = 0;
	lco.x = 0;
	t_co.y = co.y;
	t_co.x = co.x;
	while (tab[lco.y])
	{
		//printf("%d, %c\n", lco.y, ptr->next->myletter);
		while (tab[lco.y][lco.x] && tab[lco.y][lco.x] != ptr->next->myletter)
			lco.x += 1;
		while (tab[lco.y][lco.x] && tab[lco.y][lco.x] == ptr->next->myletter)
		{
			t_co.y += (lco.y - ptr->next->yaxis);
			t_co.x += (lco.x - ptr->next->xaxis);
			//printf("X %d, %d, %d, %zu, %zu\n", lco.x, t_co.y, t_co.x, ptr->next->yaxis, ptr->next->xaxis);
			if (t_co.y < 0 || t_co.x < 0 || t_co.y > (int)ft_strlen(*newtab)
			|| t_co.x > (int)ft_strlen(*newtab) || newtab[t_co.y][t_co.x] != '.')
				return (0);
			t_co.y = co.y;
			t_co.x = co.x;
			lco.x += 1;
		}
		lco.y += 1;
		lco.x = 0;
	}
	return (1);
}

int		pos_tetriminos(t_forme *ptr, char **newtab, t_coor co)
{
	int y;
	int x;
	int i;

	y = 0;
	x = 0;
	i = 0;
	printf("Yo\n");
	if (check_pos(ptr, co, ptr->next->tab, newtab) == 1)
	{
		printf("Je\n");
		while (ptr->next->tab[y])
		{
			printf("Rentre\n");
			while (ptr->next->tab[y][x] && ptr->next->tab[y][x] != ptr->next->myletter)
				x++;
			while (ptr->next->tab[y][x] && ptr->next->tab[y][x] == ptr->next->myletter)
			{
				//////PROBLEME DE COPY//////
				printf("En toi\n");
				newtab[co.y][co.x + i] = ptr->next->tab[y][x];
				x++;
				i++;
			}
			x = 0;
			i = 0;
			y++;
			co.y++;
		}
		return (1);
	}
	return (0);
}
