/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmapi_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:37:54 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/18 11:56:37 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "fillit.h"

t_forme	*ft_lstmapi_f(t_forme *lst, t_forme *(*f)(int i, t_forme *elem), int i)
{
	t_forme	*new;

	if (lst && f)
	{
		new = f(i, lst);
		lst = lst->next;
		if (lst)
			new = ft_lstmapi_f(lst, f, i + 1);
		return (new);
	}
	return (NULL);
}
