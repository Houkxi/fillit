/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_lexing_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 06:44:30 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/04 20:33:35 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "./libft/libft.h"
#include "ft_prog.h"

t_forme		*alpha_swap(int lettre, t_forme *elem)
{
	char	c;
	int		i;
	int		j;

	c = 'A';
	i = 0;
	j = 0;
	if (elem->next)
	{
		while (elem->next->tab[j])
		{
			while (elem->next->tab[j][i])
			{
				if (elem->next->tab[j][i] == '#')
					elem->next->tab[j][i] = c + lettre;
				i++;
			}
			j++;
			i = 0;
		}
		elem->next->myletter = c + lettre;
		return (elem);
	}
	return (0);
}

t_forme		*coor_search(int test, t_forme *elem)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	if (test < 0)
		return (0);
	if (elem->next)
	{
		while (elem->next->tab[j])
		{
			while (elem->next->tab[j][i] && elem->next->tab[j][i] != '#')
				i++;
			if (elem->next->tab[j][i] && elem->next->tab[j][i] == '#')
			{
				elem->next->xaxis = i;
				elem->next->yaxis = j;
				return (elem);
			}
			i = 0;
			j++;
		}
	}
	return (0);
}

static int	list_builder(char *s, int start, int len, t_forme **alst)
{
	char	*tmp;
	t_forme	*new;
	char	**tab;

	tmp = ft_strsub(s, start, len);
	if ((check_tetri(tmp, 0)) == 0)
	{
		printf("%s\n", tmp);
		free(tmp);
		return (0);
	}
	tab = ft_strsplit(tmp, '\n');
	new = ft_lstnew_re(tab, 20);
	ft_lstadd_end(alst, new);
	return (1);
}

int			checking(char *s, int col, int line, int lcount)
{
	int		nbr;

	nbr = 0;
	while (s[col] && line < 5)
	{
		while (s[col] && (s[col] == '.' || s[col] == '#'))
		{
			if (s[col] == '#')
				nbr++;
			col++;
			lcount++;
		}
		if ((s[col] && s[col] != '\n') || lcount > 5)
			return (0);
		line++;
		col++;
		lcount = 0;
	}
	if (nbr != 4 || (s[col] && (col % 21 > 0)) ||
		(!s[col] && (line + 1) % 5 > 0))
		return (0);
	else
		return (col);
}

int			square_checks(char *s, int line, int col, t_forme **ptr_lst)
{
	int		lcount;
	int		stck;
	int		nbr;

	lcount = 1;
	nbr = 0;
	while (s[col])
	{
		stck = col;
		if ((col = checking(s, col, line, lcount)) == 0)
			return (0);
		if ((list_builder(s, stck, 20, ptr_lst)) == 0)
			return (0);
		line = 0;
		nbr = 0;
	}
	//ft_lst_print(ptr_lst);
	return (col);
}
