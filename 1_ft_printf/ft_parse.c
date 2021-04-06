/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowoo <seowoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 01:32:31 by seowoo            #+#    #+#             */
/*   Updated: 2021/04/06 18:57:48 by seowoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_flag(const char **fmt, t_ftag *tag)
{
	while (**fmt == '-' || **fmt == '0')
	{
		if (**fmt == '-')
			tag->minus = 1;
		else
			tag->zero = 1;
		*fmt += 1;
	}
}

void	ft_parse_width(const char **fmt, va_list ap, t_ftag *tag)
{
	int n;

	if (**fmt == '*' || ft_isdigit(**fmt))
	{
		if (**fmt == '*')
		{
			n = va_arg(ap, int);
			if (n < 0)
			{
				tag->minus = 1;
				n *= -1;
			}
			*fmt += 1;
		}
		else
			n = ft_atoi_printf(fmt);
		tag->width = n;
	}
	if (tag->minus == 0 && tag->zero)
		tag->padding = '0';
}

void	ft_parse_precision(const char **fmt, va_list ap, t_ftag *tag)
{
	if (**fmt == '*' || ft_isdigit(**fmt))
	{
		if (**fmt == '*')
		{
			tag->precision = va_arg(ap, int);
			*fmt += 1;
		}
		else
			tag->precision = ft_atoi_printf(fmt);
	}
}

int		ft_parse(const char **fmt, va_list ap, t_ftag *tag)
{	
	ft_parse_flag(fmt, tag);
	ft_parse_width(fmt, ap, tag);
	if (**fmt == '.' && (*fmt)++)
	{
		tag->dot = 1;
		ft_parse_precision(fmt, ap, tag);
	}
	if (ft_strchr("diuxX", **fmt))
		return (ft_type_num(ap, tag, **fmt));
	else if (ft_strchr("c%", **fmt))
		return (ft_type_char(ap, tag, **fmt));
	else if (**fmt == 's')
		return (ft_type_str(ap, tag));
	else if (**fmt == 'p')
		return (ft_type_pointer(ap, tag));
	return (0);
}