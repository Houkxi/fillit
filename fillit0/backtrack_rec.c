/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_rec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:12:48 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/13 18:45:08 by mmanley          ###   ########.fr       */
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
	//printf("\n%d\n", size);
	//printf("Size %d, Pos %d, y %d, x %d\n", size, position, co->y, co->x);
	//printf("%d  DOT (%d, %d)\n\n", size, is_size_good((*ptr)->next->tab, size, newtab), check_posabilty(*ptr, *co, (*ptr)->next->tab, newtab));

	if ((is_size_good((*ptr)->next->tab, size, newtab)) == 0)
	{
		printf("WRONG SIZE\n");
		free(newtab);
		//newtab = ft_newtab(size + 1, size + 1, '.');
		return (NULL);
	}
	///////WHILE POSSIBILITY CHECK ALL OUTCOMES //////////
	if ((check_posabilty(*ptr, *co, (*ptr)->next->tab, newtab)) == 0
			&& co->y < size - 1)
	{

		/////////////PROBLEME DE CONDITION, change pos au lieu de TAILLE////////
		//printf("\nSize %d, Pos %d, y %d, x %d\n\n", size, position, co->y, co->x);
		//printf("WRONG POS   \n");
		//printf("(%d, %d), POS = %d\n", co->y, co->x, position);
		// PROBLEME, N'est pas capable de reagrandir//
		return (backy_tracky(newtab, ptr, position + 1, size));
	}

	////////////
	///////////	IF THE NEXT TETRI CAN'T FIT MOVE THIS ONE //////////////
	//////////

	if ((check_posabilty(*ptr, *co, (*ptr)->next->tab, newtab)) == 1
			&& co->y < size - 1 &&
		(check_posabilty(*ptr, *co, (*ptr)->next->next->tab, newtab)) == 0)
	{
		printf("NEW POS\n");
		return (backy_tracky(newtab, ptr, position + 1, size));
	}
/**	if (newtab[co->y] && co->y < size - 1 && newtab[co->y][co->x] != '.')
	{
		printf("Incr\n" );
		return (backy_tracky(newtab, ptr, position + 1, size));
	}*/
	else if ((pos_tetriminos(*ptr, newtab, *co)) == 0 && co->y < size - 1)
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
