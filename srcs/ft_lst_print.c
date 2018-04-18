/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:22:25 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/18 12:00:34 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include "libft.h"
#include "fillit.h"
#include <stdio.h>

void		ft_lst_print(t_forme *alst)
{
	t_forme	*tmp;
	int		i;

	i = 0;
	if (alst)
	{
		tmp = alst;
		while (tmp)
		{
			while (tmp->tab[i])
			{
				ft_putstr(tmp->tab[i]);
				ft_putchar('\n');
				i++;
			}
			ft_putchar('\n');
			tmp = tmp->next;
			i = 0;
		}
	}
}
