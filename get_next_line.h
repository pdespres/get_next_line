/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 21:00:28 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/24 12:50:57 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"

# define BUFF_SIZE 10

typedef struct		s_fd
{
	int				fd;
	char			*str;
	struct s_fd		*next;
}					t_fd;

int					get_next_line(const int fd, char **line);

#endif
