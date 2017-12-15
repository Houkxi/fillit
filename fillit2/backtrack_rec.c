/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_rec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:12:48 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/15 19:58:11 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "./libft/libft.h"
#include "ft_prog.h"


/*
		WHILE YOU CAN FIT TETRI IN SQUARE DO IT, ALTHOUGH IF NEXT ONE CAN'T FIT
		MOVE CURRENT ONE AND IF IT CAN'T GO TO THE ONE BEFORE THAT

		GERE LES CHECK DE TAILLE DIFFEREMMENT !!!!!!!
*/


int		backy_tracky(char **newtab, t_forme **ptr, int position, int size)
{
	t_coor *co = (t_coor*)malloc(sizeof(t_coor));
	int i;

	co->x = position % size;
	co->y = position / size;
	i = 0;
	if (position == size * size - 1)
		return (0);
	if ((check_posabilty(*ptr, position, (*ptr)->next->tab, newtab)) == 0 &&
		newtab[co->y][co->x] != (*ptr)->next->myletter)
		return (backy_tracky(newtab, ptr, position + 1, size));
	if ((*ptr)->next && (check_posabilty(*ptr, position, (*ptr)->next->tab, newtab)) == 1)
	{
		pos_tetriminos(*ptr, newtab, *co);
		ft_show_tab(newtab);
		printf("\n");
		while (i < size * size - 1)
		{
			if ((*ptr)->next->next && (check_posabilty((*ptr)->next, i, (*ptr)->next->next->tab, newtab)) == 1)
				return (backy_tracky(newtab, &(*ptr)->next, 0, size));
			i++;
		}
		if ((*ptr)->next->next && co->y <= size - 1 && co->x <= size - 1 &&
			(check_posabilty((*ptr)->next, position, (*ptr)->next->next->tab, newtab)) == 0)
		{
			tab_corrector(*ptr, newtab);
			i = position;
			if (check_posabilty((*ptr)->next, i, (*ptr)->next->next->tab, newtab) == 0)
			{
				while ((*ptr)->prev)
				{
					ptr = &(*ptr)->prev;
					if((position = tab_checker(*ptr, newtab)) == -1)
						return (1);
						printf("%d\n", position);
					tab_corrector(*ptr, newtab);
				}
				i++;
			}
			return (backy_tracky(newtab, ptr, position + 1, size));
		}
	}
	if ((*ptr)->next->next)
		return(backy_tracky(newtab, &(*ptr)->next, 0, size));
	return (-1);
}

/*int		backy_tracky(char **newtab, t_forme **ptr, int position, int size)
{
	t_coor *co = (t_coor*)malloc(sizeof(t_coor));
	int i;

	co->x = position % size;
	co->y = position / size;
	i = 0;
	if (co->y == size - 1 && co->x == size -1)
		return (0);
	if ((check_posabilty(*ptr, position, (*ptr)->next->tab, newtab)) == 0 &&
		newtab[co->y][co->x] != (*ptr)->next->myletter)
		return (backy_tracky(newtab, ptr, position + 1, size));
	if ((*ptr)->next && (check_posabilty(*ptr, position, (*ptr)->next->tab, newtab)) == 1)
	{
		pos_tetriminos(*ptr, newtab, *co);
		ft_show_tab(newtab);
		printf("\n");
		while (i < size * size - 1)
		{
			if ((*ptr)->next->next && (*ptr)->next && (check_posabilty((*ptr)->next, i, (*ptr)->next->next->tab, newtab)) == 1)
				return (backy_tracky(newtab, &(*ptr)->next, 0, size));
			i++;
		}
		if ((*ptr)->next->next && co->y <= size - 1 && co->x <= size - 1 &&
			(check_posabilty((*ptr)->next, i, (*ptr)->next->next->tab, newtab)) == 0)
		{
			//printf("%d, %c, %p\n", position, (*ptr)->next->myletter, (*ptr)->prev);
			tab_corrector(*ptr, newtab);
			//ft_show_tab(newtab);
			i = position;
			if (check_posabilty((*ptr)->next, i, (*ptr)->next->next->tab, newtab) == 0)
			{
				while ((*ptr)->prev)
				{
					ptr = &(*ptr)->prev;
					position = tab_checker(*ptr, newtab);
					ft_show_tab(newtab);
					tab_corrector(*ptr, newtab);
				}
				i++;
			}
					printf("%d, %c, %p\n", position, (*ptr)->next->myletter, (*ptr)->prev);
			if((*ptr)->prev)
				tab_corrector((*ptr)->prev, newtab);
			return (backy_tracky(newtab, ptr, position + 1, size));
		}
	}
	if ((*ptr)->next->next)
		return(backy_tracky(newtab, &(*ptr)->next, 0, size));
	return (size);
}*/

/*char	**backy_tracky(char **newtab, t_forme **ptr, int position, int size)
{
	t_coor *co = (t_coor*)malloc(sizeof(t_coor));
	t_forme *p = *ptr;
	int i;
	int test = 0;

	co->x = position % size;
	co->y = position / size;
	 i = 0;
	if (co->y == size - 1 && co->x == size -1)
		return (NULL);
	if ((check_posabilty(*ptr, position, p->next->tab, newtab)) == 0)
		return (backy_tracky(newtab, ptr, position + 1, size));
	while (p->next && (check_posabilty(p, position, p->next->tab, newtab)) == 1)
	{
		pos_tetriminos(p, newtab, *co);
		ft_show_tab(newtab);
		printf("\n");
		while (i < size * size - 1)
		{
			if (p->next->next && p->next && (check_posabilty(p->next, i, p->next->next->tab, newtab)) == 1)
			{
				printf("Dedans\n");
				test = -1;
				//p = p->next;
			}
			i++;
		}
		i = 0;
		if (test == -1)
			p = p->next;
		if (p->next->next && co->y <= size - 1 && co->x <= size - 1 &&
			(check_posabilty(p->next, i, p->next->tab, newtab)) == 0)
		{
			printf("Agrandir\n");
			tab_corrector(p, newtab);
			position++;
		}
		else if (position == size - 1)
		{
			return (NULL);
		}
	}
	if ((*ptr)->next->next)
	{
		printf("Vers FIN\n");
		return(backy_tracky(newtab, &(*ptr)->next, 0, size));
	}
	return (newtab);
}*/

/*char	**backy_tracky(char **newtab, t_forme **ptr, int position, int size)
{
	t_coor *co = (t_coor*)malloc(sizeof(t_coor));
	int i;

	co->x = position % size;
	co->y = position / size;
	 i = 0;
	if (co->y == size - 1 && co->x == size -1)
		return (NULL);
	if ((check_posabilty(*ptr, position, (*ptr)->next->tab, newtab)) == 0)
		return (backy_tracky(newtab, ptr, position + 1, size));
	if ((*ptr)->next && (check_posabilty(*ptr, position, (*ptr)->next->tab, newtab)) == 1)
	{
		pos_tetriminos(*ptr, newtab, *co);
		ft_show_tab(newtab);
		printf("\n");
		while (i < size * size - 1)
		{
			if ((*ptr)->next->next && (*ptr)->next && (check_posabilty((*ptr)->next, i, (*ptr)->next->next->tab, newtab)) == 1)
			{
				printf("Dedans\n");
				return (backy_tracky(newtab, &(*ptr)->next, 0, size));
			}
			i++;
		}
		if ((*ptr)->next->next && co->y <= size - 1 && co->x <= size - 1 &&
			(check_posabilty((*ptr)->next, i, (*ptr)->next->tab, newtab)) == 0)
		{
			printf("Agrandir\n");
			tab_corrector(*ptr, newtab);
			return (backy_tracky(newtab, ptr, position + 1, size));
		}
	}
	if ((*ptr)->next->next)
	{
		printf("Vers FIN\n");
		return(backy_tracky(newtab, &(*ptr)->next, 0, size));
	}
	return (newtab);
}*/

/*char	**backy_tracky(char **newtab, t_forme **ptr, int position, int size)
{
	t_coor *co = (t_coor*)malloc(sizeof(t_coor));

	co->x = position % size;
	co->y = position / size;
	int tmp = 0;
	int oth = 0;
	printf("POS = %d, SIZE = %d\n", position, size);
	if ((oth = check_posabilty(*ptr, *co, (*ptr)->next->tab, newtab)) == 1)
	{
		if ((pos_tetriminos(*ptr, newtab, *co)) == 0)
			return (NULL);
		ft_show_tab(newtab);
		printf("\n----\n");
		if ((tmp = check_posabilty(*ptr, *co, (*ptr)->next->next->tab, newtab)) == 0)
		{
			printf("%d\n", tmp);
			printf("Retry\n");
			free(newtab);
			newtab = ft_newtab(size, size, '.');
			return (backy_tracky(newtab, ptr, position + 1, size));
		}
		printf("\nTMP = %d\n", tmp);
		if  (tmp == 1)
			return (backy_tracky(newtab, &(*ptr)->next, 0, size));
		if (co->y == size - 1 && co->x == size - 1)
			return (NULL);
	}
	if (oth == 0)
	{
		printf("Yo ");
		if (co->y == size - 1 && co->x == size - 1)
		{
			ft_show_tab(newtab);
			printf("\nWRONG SIZE\n");
			return (NULL);
		}
		return (backy_tracky(newtab, ptr, position + 1, size));
	}
	if (p->next->next)
		return (backy_tracky(newtab, &p->next, 0, size));
	return (newtab);
}*/
