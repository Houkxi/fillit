/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_rec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:12:48 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/20 12:46:18 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "./libft/libft.h"
#include "ft_prog.h"

int			backy_tracky(char **nt, t_forme **p, int pos, int size)
{
	int		i;
	int		autre;

	i = 0;
	autre = 0;
	while ((*p)->prev && i != 1 && (*p)->next)
	{
		while ((*p)->next && (i = check_posabilty(*p, pos, (*p)->next->tab, nt)) == 0
		&& pos < size * size - 1)
		{
			pos++;
		}
		if (pos == size * size - 1)
		{
			p = &(*p)->prev;
			pos = tab_checker(*p, nt) + 1;
			tab_corrector(*p, nt);
			//printf("%p, %p\n", p, (*p)->prev);
			//printf("%c\n", (*p)->myl);
		}
	}
	while ((*p)->next && (i = check_posabilty(*p, pos, (*p)->next->tab, nt)) == 0
	&& pos < size * size - 1)
		pos++;
	if ((*p)->next && i == 1)
	{
		//printf("Yo\n");
		pos_tetriminos(*p, nt, pos, size);
		ft_show_tab(nt);
		return (backy_tracky(nt, &(*p)->next, 0, size));
	}
	if (!((*p)->prev) && pos == size * size - 1)
		return (0);
	return (-1);
}

/*
int		backy_tracky(char **nt, t_forme **p, int pos, int size)
{
	int		i;

	i = 0;
	while ((*p)->next && (i = check_posabilty(*p, pos, (*p)->next->tab, nt)) == 0
	&& pos < size * size - 1)
		pos++;
	if ((*p)->prev && pos == size * size - 1)
	{
		p = &(*p)->prev;
		pos = tab_checker(*p, nt);
		tab_corrector(*p, nt);
		return (backy_tracky(nt, p, pos + 1, size));
	}
	if ((*p)->next && i == 1)
	{
		pos_tetriminos(*p, nt, pos, size);
		ft_show_tab(nt);
		return (backy_tracky(nt, &(*p)->next, 0, size));
	}
	if (!((*p)->prev) && pos == size * size - 1)
		return (0);
	return (-1);
}
*/
/*
int		backy_tracky(char **nt, t_forme **p, int pos, int size)
{
	int		i;

	i = 0;
	//printf("%d, %s, (%d, %d), %d, %c\n", pos, nt[pos/ size], pos / size, pos % size, size * size - 1, (*p)->next->myl);
	if (!((*p)->prev) && pos == size * size - 1)
		return (0);
	if ((*p)->next && (check_posabilty(*p, pos, (*p)->next->tab, nt)) == 1)
	{
		write(1, "Mis\n", 4);
		pos_tetriminos(*p, nt, pos, size);
		ft_show_tab(nt);
		return (backy_tracky(nt, &(*p)->next, 0, size));
	}
	if ((*p)->prev && chk_all_psblty(*p, size, pos, nt) == 0)
	{
		write(1, "Change\n", 7);
		tab_corrector(*p, nt);
		write(1, "1\n", 2);
		p = &(*p)->prev;
		write(1, "2\n", 2);
		pos = tab_checker(*p, nt);
		write(1, "3\n", 2);
	}
	if ((*p)->next && (check_posabilty(*p, pos, (*p)->next->tab, nt)) == 0)
	{
		write(1, "No\n", 3);
		write(1, "Retry\n", 6);
		printf("%d\n", pos);
		tab_corrector(*p, nt);
		return (backy_tracky(nt, p, pos + 1, size));
	}
	return (-1);
}*/

/*
int		backy_tracky(char **nt, t_forme **p, int pos, int size)
{
	int		i;

	i = 0;
	if (!((*p)->prev) && pos == size * size - 1)
		return (0);
	if ((*p)->next && (check_posabilty(*p, pos, (*p)->next->tab, nt)) == 1)
	{
		pos_tetriminos(*p, nt, pos, size);
		ft_show_tab(nt);
		return (backy_tracky(nt, &(*p)->next, 0, size));
	}
	if ((*p)->next && (check_posabilty(*p, pos, (*p)->next->tab, nt)) == 0)
	{
		if ((*p)->prev && pos == size * size - 1)
		{
			tab_corrector(*p, nt);
			p = &(*p)->prev;
			pos = tab_checker(*p, nt);
		}
		tab_corrector(*p, nt);
		return (backy_tracky(nt, p, pos + 1, size));
	}
	return (-1);
}
*/
/*
int		backy_tracky(char **nt, t_forme **p, int pos, int size)
{
	int		i;

	i = 0;
	if (pos == size * size - 1)
		return (0);
	if ((check_posabilty(*p, pos, (*p)->next->tab, nt)) == 0)
		return (backy_tracky(nt, p, pos + 1, size));
	if ((*p)->next && (check_posabilty(*p, pos, (*p)->next->tab, nt)) == 1)
	{
		pos_tetriminos(*p, nt, pos, size);
		ft_show_tab(nt);
		///// If NEXT TETRI IS POSSIBLE/////
		if ((*p)->next->next && (chk_all_psblty((*p)->next, size, (*p)->next->next->tab, nt)) == 1)
			return (backy_tracky(nt, &(*p)->next, 0, size));
		///// If NOT POSSIBLE/////
		else if ((*p)->next->next)
		{
			if ((*p)->prev && pos / size == size - 1)
			{
				//ft_show_tab(nt);
				tab_corrector(*p, nt);
				p = &(*p)->prev;
				//printf("%c\n", (*p)->next->myl);
				pos = tab_checker(*p, nt);
				//printf("%d\n", pos);
				ft_show_tab(nt);
			}

			tab_corrector(*p, nt);
			ft_show_tab(nt);
			return (backy_tracky(nt, p, pos + 1, size));
		}
	}
	return (-1);
}*/
/*
int		backy_tracky(char **nt, t_forme **p, int pos, int size)
{
	int		i;

	i = 0;
	if (pos == size * size - 1)
		return (0);
	if ((check_posabilty(*p, pos, (*p)->next->tab, nt)) == 0)
		return (backy_tracky(nt, p, pos + 1, size));
	if ((*p)->next && (check_posabilty(*p, pos, (*p)->next->tab, nt)) == 1)
	{
		pos_tetriminos(*p, nt, pos, size);
		ft_show_tab(nt);
		if ((*p)->next->next && (chk_all_psblty((*p)->next, size, (*p)->next->next->tab, nt)) == 1)
			return (backy_tracky(nt, &(*p)->next, 0, size));
		if ((*p)->next->next && (pos / size) <= size - 1 && (pos % size) <= size - 1 &&
			(check_posabilty((*p)->next, pos, (*p)->next->next->tab, nt)) == 0)
		{
			tab_corrector(*p, nt);
			i = pos;
			if (check_posabilty((*p)->next, i, (*p)->next->next->tab, nt) == 0)
			{
				while ((*p)->prev && check_posabilty((*p)->next, i, (*p)->next->next->tab, nt) == 0)
				{
					p = &(*p)->prev;
					pos = tab_checker(*p, nt);
					tab_corrector(*p, nt);
				}
				i++;
			}
			return (backy_tracky(nt, p, pos + 1, size));
		}
	}
	return (-1);
}
*/
