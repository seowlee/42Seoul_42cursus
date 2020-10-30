/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowlee <seowlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 23:02:32 by seowlee           #+#    #+#             */
/*   Updated: 2020/10/30 11:36:47 by seowlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ndest;
	unsigned char	*nsrc;
	size_t			i;

	if (!dest || !src)
		return (0);
	ndest = (unsigned char *)dest;
	nsrc = (unsigned char *)src;
	if (dest <= src)
	{
		i = 0;
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
