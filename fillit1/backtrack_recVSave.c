/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_rec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:12:48 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/14 16:39:28 by mmanley          ###   ########.fr       */
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
char	**backy_tracky(char **newtab, t_forme **ptr, int position, int size)
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
		if  (tmp == 1)
			return (backy_tracky(newtab, &(*ptr)->next, 0, size));
		if ((tmp = check_posabilty(*ptr, *co, (*ptr)->next->next->tab, newtab)) == 0)
		{
			printf("%d\n", tmp);
			printf("Retry\n");
			free(newtab);
			newtab = ft_newtab(size, size, '.');
			backy_tracky(newtab, ptr, position + 1, size);
		}
		printf("\nTMP = %d\n", tmp);

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
	if ((*ptr)->next->next)
		return (backy_tracky(newtab, &(*ptr)->next, 0, size));
	return (newtab);
}
