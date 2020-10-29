/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowlee <seowlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 23:02:32 by seowlee           #+#    #+#             */
/*   Updated: 2020/10/28 23:59:21 by seowlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ndest;
	unsigned char	*nsrc;
	size_t			i;

	ndest = (unsigned char *)dest;
	nsrc = (unsigned char *)src;
	if (dest <= src)
	{
		while (i < n)
		{
			ndest[i] = nsrc[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			ndest[n] = nsrc[n];
	}
	return (dest);
}
