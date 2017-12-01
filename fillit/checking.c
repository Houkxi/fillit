/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:22:39 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/01 14:58:02 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "./libft/libft.h"
#include "ft_prog.h"

/*
Check if only '.' , '#', '\n', '\0' in the file,
 check if no less and more then 4 '#' and all adjacent to at lesast one other.
 and so 12 '.' per square
 */

int		occurence_counter(char *s, char c)
{
	int count;
	int i;

	count = 0;
	i = 0;
	if (!s && !*s)
		return (-1);
	while (s[i])
	{
		if (s[i] && s[i] == c)
		{
			count++;
			i++;
		}
		else if (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

int		whole_file_checking(char *str, int size)
{
	int j;
	int k;
	int l;

	/*int i = ft_strlen(str);
	printf("I = %d\n", i);*/
	if (!str && !*str)
		return (0);
	j = occurence_counter(str, '.');
	k = occurence_counter(str, '#');
	l = occurence_counter(str, '\n');
	printf("RetL__%d____ . __%d____ # __%d == %d, SIZE = %d\n", l, j, k, l + k + j, size);
	printf("%d\n", (l + 1) / 5 * 12);
	printf("%d\n", (l + 1) / 5 * 4);
	if (((l + 1) % 5) != 0)
		return (0);
	if ((j == (l + 1) / 5 * 12) && (k == ((l + 1) / 5 * 4)) &&
		size == l + j + k)
		return (1);
	else
		return (0);
}

int		check_tetri(char *str, int start)
{
	int adj;

	adj = 0;
	printf("ADJ = %d\n", adj);
	printf("Test\n");
	while (str[start])
	{
		if (str[start] && str[start] == '#')
		{
			printf("%d, ", adj);
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
	printf("Final = %d\n", adj);
	if (adj == 6 || adj == 8)
		return (1);
	else
		return (0);
}

int		square_checker(char *s, int line, int col)
{
		int nbr;
		int stck;
		char *tmp;

		nbr = 0;
		while (s[col])
		{
			stck = col;
			while (s[col] && line < 5)
			{
				while (s[col] && (s[col] == '.' || s[col] == '#'))
				{
					if (s[col] != '.' && s[col] != '#' && s[col] != '\n')
						return (0);
					if (s[col] == '#')
						nbr++;
					col++;
				}
				if (s[col] && s[col] != '\n')
					return (0);
				printf("%d__%d\n", col, line);
				line++;
				col++;
			}
			printf("MOD = %d___%d\n", col % 21, col);
			if (nbr < 4 || nbr > 4 || (s[col] && (col % 21 > 0)))
			{
				printf("NBR # Mauvais || NBR col Mauvais\n");
				return (0);
			}
			printf("%d\n", stck);
			tmp = ft_strsub(s, stck, 20);
			printf("%s\n", tmp);
			if ((check_tetri(tmp, 0)) == 0)
				return (0);
			line = 0;
			nbr = 0;
		}
		return (col);
	}
