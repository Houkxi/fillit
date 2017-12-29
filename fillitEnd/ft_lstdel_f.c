/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:44:40 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/29 17:27:02 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "ft_prog.h"

t_forme	*ft_lstdel_f(int test, t_forme *elem)
{
	t_forme *tmp;

	test += 1;
	if (elem->next)
	{
		tmp = elem;
		elem = elem->next;
		ft_deltab(tmp->tab);
		free(tmp);
		tmp = NULL;
		return (elem);
	}
	if (!elem->next)
	{
		tmp = elem;
		elem = elem->next;
		ft_deltab(tmp->tab);
		free(tmp);
		tmp = NULL;
	}
	return (0);
}
