/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_re.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:46:42 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/19 14:23:49 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "ft_prog.h"

t_forme	*ft_lstnew_re(char **content, size_t content_size)
{
	t_forme *newlst;

	if ((newlst = (t_forme*)malloc(sizeof(t_forme))) == 0)
		return (NULL);
	newlst->next = NULL;
	newlst->prev = NULL;
	if (!content)
	{
		newlst->tab = NULL;
		newlst->myl = 0;
		newlst->content_size = 0;
		newlst->xaxis = 0;
		newlst->yaxis = 0;
	}
	if (content)
	{
		if ((newlst->tab = (char**)malloc(sizeof(char*) * content_size)) == 0)
		{
			free(newlst);
			return (NULL);
		}
		newlst->tab = content;
		newlst->myl = 0;
		newlst->content_size = content_size;
		newlst->xaxis = 0;
		newlst->yaxis = 0;
	}
	return (newlst);
}
