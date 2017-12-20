/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:35:32 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/05 17:43:28 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	ft_deltab(char **tab)
{
	if (tab)
	{
		if(*tab)
		{
			free(*tab);
			*tab = NULL;
		}
		free(tab);
		tab = NULL;
	}
}
