/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_searcher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:24:13 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/07 14:20:00 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "./libft/libft.h"
#include "ft_prog.h"

t_coor		*tab_x_search(t_forme *elem)
{
	t_coor	ix;
	char	**tab;
	t_coor	*coor_hor;

	ix.x = 0;
	ix.y = 0;
	coor_hor = (t_coor*)malloc(sizeof(t_coor));
	tab = elem->next->tab;
	if (elem->next)
	{
		while (tab[ix.y])
		{
			while (tab[ix.y][ix.x] && tab[ix.y][ix.x] != elem->next->myletter)
				ix.x++;
			if (tab[ix.y][ix.x] && tab[ix.y][ix.x] == elem->next->myletter)
			{
				coor_hor->y = ix.y;
				coor_hor->x = ix.x;
				return (coor_hor);
			}
			ix.x = 0;
			ix.y++;
		}
	}
	return (NULL);
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

b_coor		*ft_all_pos(t_forme *ptr, t_coor start, b_coor *saver)
{
	char **tab;

	tab = ptr->next->tab;
	if (tab)
	{
		while (tab[y])
		{
			while (tab[y][x] && tab[y][x] == ptr->next->myletter)
			{
				if (i == 0)
				{
					saver->sec_elem.y = y;
					saver->sec_elem.x = x;
				}
				if (i == 1)
				{
					saver->sec_elem.y = y;
					saver->sec_elem.x = x;
				}
				if (i == 2)
				{
					saver->sec_elem.y = y;
					saver->sec_elem.x = x;
				}
				x++;
			}
			y++;
		}
	}

	return (b_coor);
}
