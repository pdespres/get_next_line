/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:59:26 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/24 13:00:22 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char    *str;
	int     fd;
	int		fd2;
	int		ind;
	int		ret;

	if (ac != 3)
		return (0);
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	ind = 1;
	while (1)
	{
		ret = get_next_line(fd, &str);
		if (ret > 0)
			printf("1 %s\n", str);
		ind++;
		ret = get_next_line(fd2, &str);
		if (ret > 0)
			printf("2 %s\n", str);
		if (ret <= 0)
			break ;
		ind++;
	}
	return (0);
}
