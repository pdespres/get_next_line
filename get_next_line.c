/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 20:58:24 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/21 10:43:03 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		readf(int fd, char *str)
{
	size_t	ret;
	char	*buf;
	char	*tmp;

	if (str == NULL && !(str = ft_strnew(0)))
		return (-1);
	if (!(buf = (char*)malloc(sizeof(*buf) * (BUFF_SIZE + 1))))
		return (-1);
	if ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(str, buf);
		free(buf);
		free(str);
		str = tmp;
	}
	else
		return (0);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	int			i;
	char		*ptr;

	i = read(fd, str);
	if (i <= 0)
		return (i);
	ptr = ft_strchr(str, '\n');
	while (ptr == NULL)
	{
		i = read(fd,str);
		/*	faux pour i = 0	*/
		if (i <= 0)
			return (i);
		ptr = ft_strchr(str, '\n');
	}
	*line = ft_strncpy(*line, str, (ptr - str - 1));
	ptr = ft_strsub(str, (ptr - str + 1), ft_strlen(ptr) - 1);
	free (str);
	str = ptr;
	free (ptr);
	return(1);
}

int		main(int ac, char **av)
{
	char	*str;
	int		fd;

	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &str);
	printf("%s\n", str);
	return (0);
}
