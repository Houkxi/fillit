/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_rec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:12:48 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/11 18:41:31 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./libft/libft.h"
#include "ft_prog.h"

char	**backy_tracky(char **newtab, t_forme **ptr, int position, int size)
{
	t_coor *co = (t_coor*)malloc(sizeof(t_coor));

	co->x = position % size;
	co->y = position / size;
	if (newtab[co->y][co->x] != '.')
	{
		//printf("Increment\n");
		return (backy_tracky(newtab, ptr, position + 1, size));
	}
	if ((check_pos(*ptr, *co, (*ptr)->next->tab, newtab)) == 0)
	{

		/////////////PROBLEME DE CONDITION, change pos au lieu de TAILLE////////

		printf("Je rentre\n Size %d, Pos %d, y %d, x %d\n", size, position, co->y, co->x);
		if (!newtab[co->y])
		{
			printf("WRONG SIZE\n");
			free(newtab);
			newtab = ft_newtab(size + 1, size + 1, '.');
			//return (backy_tracky(newtab, ptr, position, size + 1));
		}
		else
		{
			printf("WRONG POS%d\n", co->y);
			return (backy_tracky(newtab, ptr, position + 1, size));
		}
	}
	if ((pos_tetriminos(*ptr, newtab, *co)) == 0)
	{
		printf("Rater COPY\n");
		return (NULL);
	}
	else
		return (newtab);
}
