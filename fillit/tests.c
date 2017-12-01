/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:08:46 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/01 13:15:05 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "./libft/libft.h"
#include "ft_prog.h"

int		main(int argv, char **argc)
{
	int fd;
	int ret;
	char pretab[1024];

	if (argv == 3)
	{
		if ((fd = open (argc[2], O_RDONLY)) == -1)
			return (0);
		if ((ret = read(fd, pretab, 1024)) == -1)
			return (0);
		printf("%s\n", pretab);
		if (ft_atoi(argc[1]) == 1)
			printf("%d\n", square_checks(pretab, 0, 0));
		if (ft_atoi(argc[1]) == 2)
		{
			printf("%d\n", whole_file_checking(pretab, ret));
			printf("%d\n", square_checker(pretab, 0, 0));
		}
		//tab = ft_strsplit(pretab, '\n');
		//printf("%s\n", tab[0]);
	}
	if (argv != 3)
		{
			printf("cp ___source_file target_file\n");
		}
	return (0);
}
