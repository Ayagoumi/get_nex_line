/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 02:03:19 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/04/03 02:10:01 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	else if (s1 == NULL && s2 == NULL)
		return (1);
	if (ft_strncmp(s1, s2, n) > 0 || ft_strncmp(s1, s2, n) < 0)
		return (0);
	else if (ft_strncmp(s1, s2, n) == 0)
		return (1);
	return (0);
}
