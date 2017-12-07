/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:22:25 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/07 11:24:57 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
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
			ft_putchar('\n');
			tmp = tmp->next;
			i = 0;
		}
	}
}
