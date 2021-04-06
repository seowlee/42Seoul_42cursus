/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowlee <seowlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 11:51:50 by seowlee           #+#    #+#             */
/*   Updated: 2020/10/30 14:16:06 by seowlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t little_len;
	size_t big_len;
	size_t len2;

	if (*little == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	big_len = ft_strlen(big);
	if (big_len < little_len || len < little_len)
		return (0);
	len2 = big_len > len ? len : big_len;
	while (len2 >= little_len)
	{
		len2--;
		if (!ft_memcmp(big, little, little_len))
			return ((char *)big);
		big++;
	}
	return (0);
}
