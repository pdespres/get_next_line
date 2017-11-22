/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 20:58:24 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/22 18:57:34 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		readf(const int fd, char **str)
{
	size_t	ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	if (*str == NULL && !(*str = ft_strnew(0)))
		return (-1);
	if ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin(*str, buf)))
			return (-1);
		free(*str);
		*str = tmp;
	}
	else
		return (ret);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	int			i;
	char		*ptr;

	// BUFF_SIZE = 0 autorise? sortie actuelle en return(0)
	if (fd < 0 || BUFF_SIZE < 0 || line == NULL)
		return (-1);
	ptr = NULL;
	while (ptr == NULL)
	{
		if (ptr == str || !ptr)
			i = readf(fd, &str);
		if (i < 0)
			return (-1);
		else if (i == 0)
			// traite le eof
			return (0);
		ptr = ft_strchr(str, '\n');
	}
	if (!(*line = ft_strsub(str, 0, (ptr - str))))
		return (-1);
	// cas ou ptr == str?
	if (!(ptr = ft_strdup(ptr + 1)))
		return (-1);
	free (str);
	str = ptr;
	return(1);
}

int		main(int ac, char **av)
{
	char	*str;
	int		fd;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &str) > 0)
		printf("%s\n", str);
	return (0);
}
