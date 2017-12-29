/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_rec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:12:48 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/26 15:22:56 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./libft/libft.h"
#include "ft_prog.h"

int		backy_tracky(char **nt, t_forme *p, t_forme *head, int pos)
{
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(nt[0]);
	while (p &&
	(i = check_posabilty(p, pos, size, nt)) == 0 && pos < size * size - 1)
		pos++;
	if (p && i == 1)
	{
		pos_tetriminos(p, nt, pos, size);
		if (p->next)
			return (backy_tracky(nt, p->next, head, 0));
		return (-1);
	}
	if (p->prev != head && pos == size * size - 1)
	{
		p = p->prev;
		pos = tab_checker(p, nt);
		tab_corrector(p, nt);
		return (backy_tracky(nt, p, head, pos + 1));
	}
	if (p->prev == head && pos == size * size - 1)
		return (0);
	return (-1);
}
