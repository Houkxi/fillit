/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 06:44:30 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/01 17:16:35 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "./libft/libft.h"
#include "ft_prog.h"

/*t_forme	**list_builder(char *square)
{
	t_forme *lst;
	t_forme **stock;
	char	**tab;

	lst = ft_lstnew_re(tab, 21);
	free(tab);
	stock = &lst;
	printf("S = %p\nL = %p\n", stock, lst);
	lst = lst->next;
	printf("%s\n", (*stock)->tab[1]);
	printf("%s\n", (*stock)->tab[2]);
	printf("%s\n", (*stock)->tab[3]);
	return (stock);
}*/

int		square_checks(char *s, int line, int col)
{
	char *tmp;
	int nbr;
	int stck;
	t_forme	**ptr_lst = NULL;
	t_forme *new;
	char **tab = NULL;

	nbr = 0;
	*ptr_lst = ft_lstnew_re(NULL, 0);
	while (s[col])
	{
		stck = col;
		while (s[col] && line < 5)
		{
			while (s[col] && (s[col] == '.' || s[col] == '#'))
			{
				if (s[col] != '.' && s[col] != '#' && s[col] != '\n')
				{
					printf("Mauvais CHAR\n");
					return (0);
				}
				if (s[col] == '#')
					nbr++;
				col++;
			}
			if (s[col] && s[col] != '\n')
			{
				printf("Pas de retour ligne\n");
				return (0);
			}
			//printf("_%c_\n%d__%d\n", s[col], col, line);
			line++;
			col++;
		}
		//printf("MOD = %d___%d\n", col % 21, col);
		if (nbr < 4 || nbr > 4 || (s[col] && (col % 21 > 0)))
		{
			printf("NBR # Mauvais || NBR col Mauvais\n");
			return (0);
		}
		//printf("Col = %d, Line = %d\n", col, line);
		tmp = ft_strsub(s, stck, 20);
		tab = ft_strsplit(tmp, '\n');
		new = ft_lstnew_re(tab, 20);
		//printf("%s\n", new->tab[1]);
		ft_lstadd_end(ptr_lst, new);
		free(tab);
		free(new);
		free(tmp);
		line = 0;
		nbr = 0;
	}
	return (col);
}
