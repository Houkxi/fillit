/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:02:10 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/19 17:06:53 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "ft_prog.h"

void	ft_lstadd_end(t_forme **alst, t_forme *new)
{
	t_forme *tmp;

	if (alst && new)
	{
		if (*alst)
		{
			tmp = *alst;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
			tmp->next->prev = tmp;
		}
		else
		{
			*alst = (t_forme*)malloc(sizeof(t_forme));
			*alst = new;
		}
	}
}
