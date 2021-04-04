/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowlee <seowlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 12:12:28 by seowlee           #+#    #+#             */
/*   Updated: 2020/11/03 10:18:34 by seowlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_num_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	size_t		n_len;
	size_t		sign;
	char		*result;
	long long	n1;

	n_len = get_num_len(n);
	result = (char *)malloc(sizeof(char) * (n_len + 1));
	if (result == NULL)
		return (NULL);
	result[n_len] = '\0';
	sign = 0;
	n1 = (long long)n;
	if (n1 < 0)
	{
		n1 *= -1;
		result[0] = '-';
		sign = 1;
	}
	while (n_len-- > sign)
	{
		result[n_len] = (n1 % 10) + '0';
		n1 /= 10;
	}
	return (result);
}
