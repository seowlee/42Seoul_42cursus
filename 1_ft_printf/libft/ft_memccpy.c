/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowlee <seowlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:33:33 by seowlee           #+#    #+#             */
/*   Updated: 2020/10/28 21:00:47 by seowlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ndest;
	unsigned char	*nsrc;
	unsigned char	ch;
	size_t			i;

	ndest = (unsigned char *)dest;
	nsrc = (unsigned char *)src;
	ch = c;
	i = 0;
	while (i < n)
	{
		ndest[i] = nsrc[i];
		if (nsrc[i] == ch)
			return (ndest + (i + 1));
		i++;
	}
	return (0);
}
