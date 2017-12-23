/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_re.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:46:42 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/23 18:02:14 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "ft_prog.h"

t_forme	*ft_lstnew_re(char **content)
{
	t_forme *newlst;

	if ((newlst = (t_forme*)malloc(sizeof(t_forme))) == 0)
		return (NULL);
	if ((newlst->cmps = (t_coor*)malloc(sizeof(t_coor))) == 0)
	{
		free(newlst);
		return (NULL);
	}
	newlst->cmps->y1 = 0;
	newlst->cmps->x1 = 0;
	newlst->cmps->y2 = 0;
	newlst->cmps->x2 = 0;
	newlst->cmps->y3 = 0;
	newlst->cmps->x3 = 0;
	newlst->next = NULL;
	newlst->prev = NULL;
	newlst->myl = 0;
	newlst->xaxis = 0;
	newlst->yaxis = 0;
	if (!content)
		newlst->tab = NULL;
	if (content)
	{
		newlst->tab = content;
	}
	return (newlst);
}
