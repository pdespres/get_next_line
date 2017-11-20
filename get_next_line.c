/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 20:58:24 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/20 21:30:04 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd)
{
	size_t	ret;
	size_t	buf_size;
	char	*buf;
	char	*str;
	char	*tmp;

	buf_size = BUF_SZ;
	if (!(str = (char*)malloc(1)))
		return (NULL);
	if (!(buf = (char*)malloc(sizeof(*buf) * (BUFF_SIZE + 1))))
		return (NULL);
	str[0] = '\0';
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(str, buf);
		free(buf);
		free(str);
		str = tmp;
		if (!(buf = (char*)malloc(sizeof(*buf) * (buf_size + 1))))
			return (NULL);
	}
	return (str);
}

int		get_next_line(const int fd, char **line)
{

}
