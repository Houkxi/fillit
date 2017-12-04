/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_lexing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:22:39 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/04 19:08:08 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "./libft/libft.h"
#include "ft_prog.h"

int			check_tetri(char *str, int start)
{
	int		adj;

	adj = 0;
	while (str[start])
	{
		if (str[start] && str[start] == '#')
		{
			if (str[start + 1] == '#')
				adj++;
			if (str[start - 1] == '#')
				adj++;
			if (str[start + 5] == '#')
				adj++;
			if (str[start - 5] == '#')
				adj++;
			start++;
		}
		else
			start++;
	}
	if (adj == 6 || adj == 8)
		return (1);
	else
		return (0);
}

int			square_checker(char *s, int line, int col, int nbr)
{
	int		stck;
	int		lcount;
	char	*tmp;

	lcount = 0;
	while (s[col])
	{
		stck = col;
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
		tmp = ft_strsub(s, stck, 20);
		if ((check_tetri(tmp, 0)) == 0)
			return (0);
		line = 0;
		nbr = 0;
	}
	return (col);
}
