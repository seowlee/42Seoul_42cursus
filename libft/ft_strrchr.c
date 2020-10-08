/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowlee <seowlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 20:11:53 by seowlee           #+#    #+#             */
/*   Updated: 2020/10/07 11:24:56 by seowlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int character)
{
	int len;

	len = ft_strlen(str);
	while (len)
	{
		if (str[len] == character)
			return ((char *)(str + len));
		len--;
	}
	return (0);
}
