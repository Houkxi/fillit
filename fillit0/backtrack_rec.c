/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_rec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:12:48 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/14 14:48:32 by mmanley          ###   ########.fr       */
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
	printf("\n%d\n", size);
	//printf("Size %d, Pos %d, y %d, x %d----------", size, position, co->y, co->x);
	//printf("%d  Possible (%d, %d)\n\n", size, is_size_good((*ptr)->next->tab, size, newtab), check_posabilty(*ptr, *co, (*ptr)->next->tab, newtab));
	if ((check_posabilty(*ptr, *co, (*ptr)->next->tab, newtab)) == 0)
	{
		if (co->y == size - 1 && co->x == size - 1)
		{
			printf("WRONG SIZE\n");
			free(newtab);
			return (NULL);
		}
		printf("WRONG POS   \n");
		return (backy_tracky(newtab, ptr, position + 1, size));
	}
	printf("Good\n");
	if ((pos_tetriminos(*ptr, newtab, *co)) == 0 && co->y < size - 1)
	{
		printf("Rater COPY\n");
		return (NULL);
	}
	ft_show_tab(newtab);
	printf("\n");
	if ((*ptr)->next->next)
		return (backy_tracky(newtab, &(*ptr)->next, 0, size));
	return (newtab);
}
