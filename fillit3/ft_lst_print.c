/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:22:25 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/19 16:39:22 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include "ft_prog.h"
#include "./libft/libft.h"

void		ft_lstprint(t_forme **alst)
{
	t_forme	*tmp;
	int		i;

	i = 0;
	if (alst)
	{
		tmp = *alst;
		while (tmp->next)
		{
			while (tmp->next->tab[i])
			{
				ft_putstr(tmp->next->tab[i]);
				ft_putchar('\n');
				i++;
			}
			ft_putchar('\n');
			tmp = tmp->next;
			i = 0;
		}
	}
}
