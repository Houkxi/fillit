/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_rec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:12:48 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/23 17:20:20 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "./libft/libft.h"
#include "ft_prog.h"

/*
int			backy_tracky(char **nt, t_forme *p, int pos, int size)
{
	int		i;

	i = 0;
	while (p->prev && i != 1 && p->next)
	{
		while (p->next && pos < size * size - 1
		(i = check_posabilty(p, pos, p->tab, nt)) == 0)
			pos++;
		if (pos == size * size - 1)
		{
			p = p->prev;
			pos = tab_checker(p, nt) + 1;
			tab_corrector(p, nt);
		}
	}
	while ((*p)->next && pos < size * size - 1 &&
	(i = check_posabilty(p, pos, p->tab, nt)) == 0)
		pos++;
	if (p->next && i == 1)
	{
		pos_tetriminos(p, nt, pos, size);
		return (backy_tracky(nt, p->next, 0, size));
	}
	if (!(p->prev) && pos == size * size - 1)
		return (0);
	return (-1);
}
*/

int		backy_tracky(char **nt, t_forme *p, t_forme *head, int pos)
{
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(nt[0]);
	while (p &&
	(i = check_posabilty(p, pos, size, nt)) == 0 && pos < size * size - 1)
		pos++;
	if (p && i == 1)
	{
		pos_tetriminos(p, nt, pos, size);
		//ft_show_tab(nt);
		if (p->next)
			return (backy_tracky(nt, p->next, head, 0));
		return (-1);
	}
	if (p->prev != head && pos == size * size - 1)
	{
		p = p->prev;
		pos = tab_checker(p, nt);
		tab_corrector(p, nt);
		return (backy_tracky(nt, p, head, pos + 1));
	}
	if (p->prev == head && pos == size * size - 1)
		return (0);
	return (-1);
}
