/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:37:54 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/04 18:26:12 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_prog.h"
#include "./libft/libft.h"

t_forme	*ft_lstmapi(t_forme *lst, t_forme *(*f)(int i, t_forme *elem), int i)
{
	t_forme	*new;

	if (lst && f)
	{
		new = f(i, lst);
		lst = lst->next;
		if (lst)
			new = ft_lstmapi(lst, f, i + 1);
		return (new);
	}
	return (NULL);
}
