/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_re.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:46:42 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/20 18:52:27 by mmanley          ###   ########.fr       */
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
	newlst->next = NULL;
	newlst->prev = NULL;
	newlst->myl = 0;
	newlst->xaxis = 0;
	newlst->yaxis = 0;
	if (!content)
		newlst->tab = NULL;
	if (content)
	{
		if ((newlst->tab = (char**)malloc(sizeof(char*) * 20)) == 0)
		{
			free(newlst);
			return (NULL);
		}
		newlst->tab = content;
	}
	return (newlst);
}
