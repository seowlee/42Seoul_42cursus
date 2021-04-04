/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowlee <seowlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 23:33:05 by seowlee           #+#    #+#             */
/*   Updated: 2020/11/03 10:56:02 by seowlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*s2;
	char	find;

	i = ft_strlen(s);
	s2 = (char *)s;
	find = (char)c;
	while (i > 0)
	{
		if (s2[i] == find)
			return (s2 + i);
		i--;
	}
	if (s2[i] == find)
		return (s2);
	return (0);
}
