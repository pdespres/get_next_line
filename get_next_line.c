/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 20:58:24 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/24 13:00:05 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

static t_fd		*init_lst(t_fd **prems, const int fd)
{
	t_fd			*temp;

	temp = *prems;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	if ((temp = (t_fd*)malloc(sizeof(*temp))) == NULL)
		return (NULL);
	temp->fd = fd;
	temp->next = *prems;
	if ((temp->str = ft_strnew(0)) == NULL)
		return (NULL);
	*prems = temp;
	return (temp);
}

static int		readf(const int fd, char **str, char **ptr)
{
	ssize_t			ret;
	char			*buf;
	char			*tmp;

	if ((buf = (char*)malloc(BUFF_SIZE + 1)) == NULL)
		return (-1);
	ret = (int)read(fd, buf, BUFF_SIZE);
	if (ret > 0)
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin(*str, buf)))
			return (-1);
		ft_free(*str);
		ft_free(buf);
		*str = tmp;
		*ptr = ft_strchr(*str, '\n');
	}
	else if (ret == 0 && ft_strlen(*str) > 0)
	{
		if ((*ptr = ft_strchr(*str, '\n')) == NULL)
			*ptr = *str + ft_strlen(*str);
	}
	else if (ret <= 0)
		return (ret);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_fd		*prems = NULL;
	t_fd			*lst;
	int				i;
	char			*ptr;

	if (fd < 0 || BUFF_SIZE <= 0 || line == NULL
			|| ((lst = init_lst(&prems, fd)) == NULL))
		return (-1);
	ptr = ft_strchr(lst->str, '\n');
	while (ptr == NULL)
	{
		i = readf(fd, &lst->str, &ptr);
		if (i == -1)
			return (-1);
		else if (i == 0)
			return (0);
	}
	if ((*line = ft_strsub(lst->str, 0, (ptr - lst->str))) == NULL)
		return (-1);
	if (!(ptr = ft_strdup(ptr + (*ptr == '\0' ? 0 : 1))))
		return (-1);
	ft_free(lst->str);
	lst->str = ptr;
	return (1);
}
