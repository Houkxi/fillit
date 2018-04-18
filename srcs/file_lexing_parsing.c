/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_lexing_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 06:44:30 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/22 15:06:33 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include "fillit.h"

t_forme			*alpha_swap(int lettre, t_forme *elem)
{
	char		c;
	int			i;
	int			j;

	c = 'A';
	i = 0;
	j = 0;
	if (elem)
	{
		while (elem->tab[j])
		{
			while (elem->tab[j][i])
			{
				if (elem->tab[j][i] == '#')
					elem->tab[j][i] = c + lettre;
				i++;
			}
			j++;
			i = 0;
		}
		elem->myl = c + lettre;
		return (elem);
	}
	return (0);
}

t_forme			*coor_search(int test, t_forme *elem)
{
	int			j;
	int			i;

	j = 0;
	i = 0;
	if (test < 0)
		return (0);
	if (elem)
	{
		while (elem->tab[j])
		{
			while (elem->tab[j][i] && elem->tab[j][i] != '#')
				i++;
			if (elem->tab[j][i] && elem->tab[j][i] == '#')
			{
				elem->xaxis = i;
				elem->yaxis = j;
				return (elem);
			}
			i = 0;
			j++;
		}
	}
	return (0);
}

static t_forme	*list_builder(char *s, int start, int len, t_forme *alst)
{
	char		*tmp;
	t_forme		*new;
	char		**tab;

	tmp = ft_strsub(s, start, len);
	if ((check_tetri(tmp, 0)) == 0)
	{
		free(tmp);
		return (NULL);
	}
	tab = ft_strsplit(tmp, '\n');
	free(tmp);
	tmp = NULL;
	new = ft_lstnew_re(tab);
	ft_lstadd_end(&alst, new);
	return (alst);
}

static int		checking(char *s, int col, int line, int lcount)
{
	int			nbr;

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

int				square_checks(char *s, int max, int col, t_forme **ptr_lst)
{
	int			lcount;
	int			stck;

	lcount = 1;
	while (s[col])
	{
		stck = col;
		if ((col = checking(s, col, 0, lcount)) == 0)
			return (0);
		if (!s[col])
			col += 1;
		if (col % 21 != 0)
			return (0);
		if ((*ptr_lst = list_builder(s, stck, 20, *ptr_lst)) == NULL)
		{
			ft_lstmapi_f(*ptr_lst, &ft_lstdel_f, 0);
			return (0);
		}
		max++;
	}
	if (max > 26)
		return (0);
	return (col);
}
