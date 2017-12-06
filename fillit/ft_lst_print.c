/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:22:25 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/05 17:41:21 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_prog.h"
#include "./libft/libft.h"

void	ft_lst_print(t_forme **alst)
{
	t_forme *tmp;
	int i;
	int j;

	i = 0;
	j = 0;
	if (alst)
	{
		tmp = *alst;
		while (tmp->next)
		{
			while (tmp->next->tab[i])
			{
				ft_putstr(tmp->next->tab[i]);
				if (i == 2)
				{
					write(1, " Num : ", 7);
					ft_putnbr(j);
					write(1, "  |  My Letter = ", 17);
					ft_putchar(tmp->next->myletter);
					write (1, "   |  Y =  ", 11);
					ft_putnbr(tmp->next->yaxis);
					write(1, ",   X =  ",9);
					ft_putnbr(tmp->next->xaxis);
					j++;
				}
				ft_putchar('\n');
				i++;
			}
			//write(1, " |\n |\n v\n", 12);
			ft_putchar('\n');
			tmp = tmp->next;
			i = 0;
		}
	}
}

void	show_tab(char **tab)
{
	int k;
	int j;

	k = 0;
	j = 0;
	if (tab)
	{
		printf("ShowTAB\n");
		while (tab[k])
		{
			while (tab[k][j])
			{
				ft_putchar(tab[k][j]);
				j++;
			}
			ft_putchar('\n');
			j = 0;
			k++;
		}
	}
}
