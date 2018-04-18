/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_re.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:46:42 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/18 11:05:17 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

t_forme	*ft_lstnew_re(char **content)
{
	t_forme *newlst;

	if ((newlst = (t_forme*)malloc(sizeof(t_forme))) == 0)
		return (NULL);
	newlst->next = NULL;
	newlst->myl = 0;
	newlst->xaxis = 0;
	newlst->yaxis = 0;
	if (!content)
		newlst->tab = NULL;
	if (content)
		newlst->tab = content;
	return (newlst);
}
