/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_occ_counter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 19:04:17 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/04 19:05:44 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

int		ft_occ_counter(char *s, char c)
{
	int count;
	int i;

	count = 0;
	i = 0;
	if (!s && !*s)
		return (-1);
	while (s[i])
	{
		if (s[i] && s[i] == c)
		{
			count++;
			i++;
		}
		else if (s[i] && s[i] != c)
			i++;
	}
	return (count);
}
