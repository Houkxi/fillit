/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_searcher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:24:13 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/15 14:11:33 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../libft/libft.h"
#include "../ft_prog.h"

int		tab_x_search(t_forme *elem, char **tab)
{
	t_coor	ix;
	int		i;

	ix.x = 0;
	ix.y = 0;
	i = 0;
	if (elem->next)
	{
		while (tab[ix.y])
		{
			while (tab[ix.y][ix.x] && tab[ix.y][ix.x] != elem->next->myletter)
				ix.x++;
			if (tab[ix.y][ix.x] && tab[ix.y][ix.x] == elem->next->myletter)
			{
				return(i);
			}
			i +=ix.x;
			ix.x = 0;
			ix.y++;
		}
	}
	return (0);
}

t_coor		*tab_y_search(t_forme *elem)
{
	t_coor	iy;
	char	**tab;
	t_coor	*coor_ver;

	iy.x = 0;
	iy.y = 0;
	tab = elem->next->tab;
	coor_ver = (t_coor*)malloc(sizeof(t_coor));
	if (elem->next)
	{
		while (tab[iy.y][iy.x] && tab[iy.y])
		{
			while (tab[iy.y] && tab[iy.y][iy.x] != elem->next->myletter)
				iy.y++;
			if (tab[iy.y] && tab[iy.y][iy.x] == elem->next->myletter)
			{
				coor_ver->y = iy.y;
				coor_ver->x = iy.x;
				return (coor_ver);
			}
			iy.y = 0;
			iy.x++;
		}
	}
	return (NULL);
}

b_coor	*ft_all_pos(t_forme *ptr, b_coor *saver)
{
	char **tab;
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	tab = ptr->next->tab;
	if (tab)
	{
		printf("Yo\n");
		while (tab[y])
		{
			printf("Je Rentre\n");
			printf("%s\n", tab[y]);
			while (tab[y][x] && tab[y][x] != ptr->next->myletter)
				x++;
			while (tab[y][x] && tab[y][x] == ptr->next->myletter)
			{
				printf("ICI\n");
				if (i == 1)
				{
					printf("(%d, %d)\n", y, x);
					saver->sec_elem.y = y;
					saver->sec_elem.x = x;
				}
				if (i == 2)
				{
					printf("(%d, %d)\n", y, x);
					saver->third_elem.y = y;
					saver->third_elem.x = x;
				}
				if (i == 3)
				{
					printf("(%d, %d)\n", y, x);
					saver->fourth_elem.y = y;
					saver->fourth_elem.x = x;
				}
				i++;
				x++;
			}
			x = 0;
			y++;
		}
	}
	return (saver);
}
