/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 20:14:37 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/06/10 22:09:33 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# define BUFF_SIZE 20

int				get_next_line(const int fd, char **line);

typedef struct	s_gnl
{
	int				fd;
	char			*content;
	struct s_gnl	*next;
}				t_gnl;

#endif
