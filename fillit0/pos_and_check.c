/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_and_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:52:06 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/13 18:40:43 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./libft/libft.h"
#include "ft_prog.h"

int		check_posabilty(t_forme *ptr, t_coor co, char **tab, char **newtab)
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
			//printf("\nLOCAL : (%d, %d)\nTMP : (%d, %d)\nPTR COOR : (%zu, %zu)\n\n", lco.y, lco.x, t_co.y, t_co.x, ptr->next->yaxis, ptr->next->xaxis);
			if (t_co.y < 0 || t_co.x < 0 || t_co.y > (int)ft_strlen(*newtab)
			|| t_co.x > (int)ft_strlen(*newtab) || newtab[t_co.y][t_co.x] != '.')
			{
				//printf("\nEL GROS :\nCoor (%d, %d)\nSize %d\n\n", t_co.y, t_co.x, (int)ft_strlen(*newtab));
				return (0);
			}
			t_co.y = co.y;
			t_co.x = co.x;
			lco.x += 1;
		}
		lco.y += 1;
		lco.x = 0;
	}
	return (1);
}

int		is_size_good(char **tab, int size, char **newtab)
{
	//////////PAS BON, MAUVAIS CHECK, NE FONCTIONNE PAS DANS TOUS LES CAS/////////
	//ft_show_tab(newtab);
	printf("\n");
	//ft_show_tab(tab);
	printf("%d   SIZE (%d, %d), DOT (%d, %d)\n", size, tab_y_size(tab), tab_x_size(tab), dot_y_size(newtab), dot_x_size(newtab));
	int y;
	int x;

	y = tab_y_size(newtab);
	x = tab_x_size(newtab);
	size = x;
	//ft_show_tab(newtab);
	//printf("Siz (%d, %d)\n", y, x);
	if((tab_y_size(tab)) > dot_y_size(newtab) || (tab_x_size(tab)) > dot_x_size(newtab))
		return (0);
	return (1);
}

int		pos_tetriminos(t_forme *ptr, char **newtab, t_coor co)
{
	int y;
	int tmp;
	int x;
	int i;

	y = 0;
	x = 0;
	i = 0;
	tmp = co.x;
//	printf("Yo, (%d, %d)\n", co.y, co.x);
	if (check_posabilty(ptr, co, ptr->next->tab, newtab) == 1)
	{
	//	printf("Je\n");
		while (ptr->next->tab[y])
		{
		//	printf("Rentre\n");
			while (ptr->next->tab[y][x] && ptr->next->tab[y][x] != ptr->next->myletter)
				x++;
			while (ptr->next->tab[y][x] && ptr->next->tab[y][x] == ptr->next->myletter)
			{
				//////PROBLEME DE COPY//////
			//	printf("En toi\n");
				//printf("%d, %s\n", co.y, newtab[co.y]);
			//	printf("\n(%d, %d)\n\n",  co.y, co.x);
				co.x += (int)(x - (int)ptr->next->xaxis);
				//printf("POs : (%d, %d)\nLx et PtrX : (%d, %zu)\n:Sou = %d\n", co.y, co.x, x, ptr->next->xaxis, x - (int)ptr->next->xaxis);
				newtab[co.y][co.x] = ptr->next->tab[y][x];
				//printf("%s\n", newtab[co.y]);
				if (co.x != tmp)
					co.x = tmp;
				x++;
				i++;
			}
			if (i != 0)
			{
				co.y++;
			}
			x = 0;
			i = 0;
			y++;
		}
		return (1);
	}
	return (0);
}
