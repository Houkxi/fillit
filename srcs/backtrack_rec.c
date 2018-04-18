/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_rec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:12:48 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/18 13:40:46 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libft.h"
#include "fillit.h"
#include <stdio.h>

int		backy_tracky(char **nt, t_forme *p, int sz, int pos)
{
	int		i;

	i = 0;
	while (p && pos < sz * sz - 1)
	{
		if (p && i == 1)
		{
			pos_tetriminos(p, nt, pos, sz);
			pos = 0;
			if ((backy_tracky(nt, p->next, sz, pos)))
				return (-1);
			else if ((pos = tab_checker(p, nt) + 1) != 0)
				tab_corrector(p, nt);
		}
		if ((i = check_posabilty(p, pos, sz, nt)) == 0 && pos < sz * sz - 1)
			pos++;
	}
	if (!p)
		return (-1);
	else
		return (0);
}
