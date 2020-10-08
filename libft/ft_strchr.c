/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowlee <seowlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 15:45:38 by seowlee           #+#    #+#             */
/*   Updated: 2020/10/07 11:25:15 by seowlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int character)
{
	int i;

	i = 0;
	while (str[i] != (char)character)
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return ((char *)(str + i));
}
