/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 20:58:24 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/23 19:12:37 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void		ft_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

static int		readf(const int fd, char **str)
{
	ssize_t	ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	if (*str == NULL && !(*str = ft_strnew(0)))
	{
		return (-1);
	}
	ret = (int)read(fd, buf, BUFF_SIZE);
	if (ret > 0)
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin(*str, buf)))
			return (-1);
		ft_free(*str);
		*str = tmp;
	}
	else if (ret == 0 && ft_strlen(*str) > 0)
		return (-2);
	else if (ret <= 0)
		return (ret);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	int			i;
	char		*ptr;

	if (fd < 0 || BUFF_SIZE < 0 || line == NULL)
		return (-1);
	ptr = (str == NULL ? NULL : ft_strchr(str, '\n'));
	while (ptr == NULL)
	{
		if (ptr == str || !ptr)
		{
			i = readf(fd, &str);
			if (i == -1)
				return (-1);
			else if (i == 0)
				return (0);
		}
		ptr = ft_strchr(str, '\n');
		if (ptr == NULL && i == -2)
		{
			ptr = str + ft_strlen(str);
		}
	}
	if ((*line = ft_strsub(str, 0, (ptr - str))) == NULL)
	{
		return (-1);
	}
	if (!(ptr = ft_strdup(ptr + (*ptr == '\0' ? 0 : 1))))
	{
		return (-1);
	}
	ft_free (str);
	str = ptr;
	return (1);
}
