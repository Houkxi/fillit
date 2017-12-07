/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:44:40 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/07 12:31:45 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../ft_prog.h"

void	ft_lstdel_f(t_forme **alst, void (*del)(char, size_t, size_t, size_t))
{
	t_forme *tmp;

	if (*alst)
	{
		while (*alst)
		{
			tmp = *alst;
			*alst = (*alst)->next;
			ft_deltab(tmp->tab);
			del(tmp->myletter, tmp->content_size, tmp->xaxis, tmp->yaxis);
			free(tmp);
		}
		*alst = NULL;
	}
}
