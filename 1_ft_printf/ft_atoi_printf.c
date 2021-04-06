/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowoo <seowoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 02:31:50 by seowoo            #+#    #+#             */
/*   Updated: 2021/04/06 19:04:22 by seowoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi_printf(const char **str)
{
	long long	num;
	int			sign;
	int			i;

	num = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(**str))
		*str += 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign *= -1;
		i++;
	}
	while (**str >= '0' && **str <= '9')
	{
		num = num * 10;
		num += *(*str)++ - '0';
	}
	return (sign * num);
}
