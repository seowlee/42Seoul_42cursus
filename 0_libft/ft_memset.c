/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowlee <seowlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 21:05:56 by seowlee           #+#    #+#             */
/*   Updated: 2020/10/08 21:39:10 by seowlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	fillchar;

	tmp = (unsigned char *)dest;
	fillchar = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		*(tmp + i) = fillchar;
		i++;
	}
	return (dest);
}
