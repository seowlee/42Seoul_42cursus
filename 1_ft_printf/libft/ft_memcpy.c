/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowlee <seowlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:39:29 by seowlee           #+#    #+#             */
/*   Updated: 2020/11/11 21:34:52 by seowlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ndest;
	unsigned char	*nsrc;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (NULL);
	ndest = (unsigned char *)dest;
	nsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ndest[i] = nsrc[i];
		i++;
	}
	return (dest);
}
