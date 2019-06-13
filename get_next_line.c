/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:01:19 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/06/13 14:46:46 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
static t_gnl	*gnl_new(int fd)
{
	t_gnl	*new;

	if (!(new = (t_gnl*)malloc(sizeof(t_gnl))))
		return (NULL);
	new->content = ft_strnew(0);
	new->fd = fd;
	return (new);
}

static t_gnl	*get_cur_file(int fd, t_gnl **files)
{
	t_gnl *tmp;

	tmp = *files;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = gnl_new(fd);
	tmp->next = *files;
	*files = tmp;
	return (tmp);
}

static int		ilen(char *r)
{
	int i;

	i = 0;
	while (r[i] && r[i] != '\n')
		i++;
	return (i);
}

static int		reading(const int fd, char **content)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	int		re;

	while ((re = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[re] = '\0';
		tmp = *content;
		*content = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	re += ft_strlen(*content);
	return (re);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*file;
	t_gnl			*fl;
	int				re;
	char			*tmp;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	fl = get_cur_file(fd, &file);
	re = reading(fd, &fl->content);
	if (re == -1)
		return (-1);
	*line = ft_strsub((fl->content), 0, ilen(fl->content));
	tmp = fl->content;
	if ((fl->content[ilen(tmp)]))
		fl->content = ft_strdup(ft_strchr(fl->content, '\n') + 1);
	else
		fl->content = ft_strnew(0);
	ft_strdel(&tmp);
	if (re == 0 && *fl->content == '\0' && **line == '\0')
		return (0);
	return (1);
}
