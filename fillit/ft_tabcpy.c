/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:14:47 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/01 11:33:15 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ft_prog.h"

void	ft_tabcpy(char **tab, char **t)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (j < 4)
	{
		printf("CPY\n");
		while (t[j][i])
		{
			printf("%c\n", t[j][i]);
			tab[j][i] = t[j][i];
			printf("%c\n", tab[j][i]);
			i++;
		}
			tab[j][i] = '\0';
			printf("__%s\n", tab[j]);
			j++;
			i = 0;
	}
}
