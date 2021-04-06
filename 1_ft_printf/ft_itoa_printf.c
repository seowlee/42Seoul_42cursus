/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowoo <seowoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 02:31:04 by seowoo            #+#    #+#             */
/*   Updated: 2021/04/06 17:14:23 by seowoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_len_base(long long n, int base)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / base;
	}
	return (len);
}

int		ft_add_len(int length, t_ftag *tag, long long n)
{
	if (length < tag->precision)
		length = tag->precision;
	if (n < 0)
		length += 1;
	return (length);
}

char	*ft_itoa_printf(int n, t_ftag *tag)
{
	long long	num;
	int			len;
	char		*str;

	num = n;
	len = ft_get_len_base(num, 10);
	len = ft_add_len(len, tag, num);
	str = (char *)ft_calloc(len + 1, 1);
	if (!str)
		return (0);
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	str[len--] = 0;
	while (1)
	{
		if (str[len] == '-' || len < 0)
			break;
		str[len--] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}

char	*ft_itoa_base(unsigned int n, char *base, t_ftag *tag)
{
	long long	num;
	int			len;
	int			base_len;
	char		*str;

	num = n;
	base_len = ft_strlen(base);
	len = ft_get_len_base(num, base_len);
	if (len < tag->precision)
		len = tag->precision;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (num == 0)
		str[0] = '0';
	str[len--] = 0;
	while (len >= 0)
	{
		str[len--] = base[num % base_len];
		num /= base_len;
	}
	return (str);
}

char	*ft_itoa_l_base(unsigned long n, char *base, t_ftag *tag)
{
	long long	num;
	int			len;
	int			base_len;
	char		*str;

	num = n;
	base_len = ft_strlen(base);
	len = ft_get_len_base(num, base_len);
	if (len < tag->precision)
		len = tag->precision;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (num == 0)
		str[0] = '0';
	str[len--] = 0;
	while (len >= 0)
	{
		str[len--] = base[num % base_len];
		num /= base_len;
	}
	return (str);
}