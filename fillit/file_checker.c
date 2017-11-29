/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:22:39 by mmanley           #+#    #+#             */
/*   Updated: 2017/11/29 18:36:19 by mmanley          ###   ########.fr       */
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

int		check_tetri(char *str, int start, int len)
{
	int count;

	count = 0;
	while (start < len)
	{
		if (str[start] == '#')
		{
			count++;
			if ((str[start + 1] != '#' || str[start + 5] != '#') && count < 4)
				return (0);
			if (count == 4 && (str[start - 1] != '#' || str[start - 5] != '#'))
				return (0);
			start++;
		}
		if (str[start] == '.' || str[start] == '\n')
			start++;

	}
	if (count == 4)
		return (1);
	return (0);
}

int		square_checker(char *str, int i)
{
	int j;
	int k;

	j = 0;
	k = 0;
	printf("GOOD\n");
	while (str[i])
	{
		if (str[i])
		{
			printf("I = %d\n", i);
			printf("_%c_\n", str[i]);
			printf("%d\n", check_tetri(str, i, 20));
		}
		while (str[i] && j < 4)
		{
			if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
				return (0);
			if (str[i] == '\n')
			{
					j++;
					i++;
			}
			if (str[i] == '.' || str[i] == '#')
			{
				i++;
			}
			printf("WHAT%d\n", i);
		}

		if (str[i] != '\0' && str[i] != '\n')
			return (0);
		if (str[i])
		{
			k = 0;
			j = 0;
		}
		i++;
	}
	return (1);
}
