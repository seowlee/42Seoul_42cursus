/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowoo <seowoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:56:01 by seowoo            #+#    #+#             */
/*   Updated: 2021/04/06 17:11:34 by seowoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_num(va_list ap, t_ftag *tag, char type)
{
	char	*src;
	int		count;
	int		num;

	src = 0;
	if (tag->dot && tag->precision >= 0)
		tag->padding = ' ';
	num = va_arg(ap, int);
	if (tag->dot && tag->precision == 0 && num == 0)
		src = ft_strdup("");
	else
	{
		if (type == 'd' || type == 'i')
			src = ft_itoa_printf(num, tag);
		else if (type == 'u')
			src = ft_itoa_base(num, "0123456789", tag);
		else if (type == 'x')
			src = ft_itoa_base(num, "0123456789abcdef", tag);
		else if (type == 'X')
			src = ft_itoa_base(num, "0123456789ABCDEF", tag);
	}
	count = ft_print_len(tag, src);
	free(src);
	return (count);
}

int	ft_type_char(va_list ap, t_ftag *tag, char type)
{
	char	chr;
	int		count;

	chr = '%';
	if (type == 'c')
		chr = va_arg(ap, int);
	count = 1;
	if (tag->width > 1)
	{
		count += tag->width - 1;
		if (tag->minus)
		{
			ft_putchar_fd(chr, 1);
			ft_iter_putchar_fd(tag->padding, 1, tag->width - 1);
		}
		else
		{
			ft_iter_putchar_fd(tag->padding, 1, tag->width - 1);
			ft_putchar_fd(chr, 1);
		}
	}
	else
		ft_putchar_fd(chr, 1);
	return (count);
}

int	ft_type_str(va_list ap, t_ftag *tag)
{
	char	*src;
	char	*temp;
	int		count;

	temp = va_arg(ap, char *);
	if (!temp)
		temp = ft_strdup("(null)");
	else
		temp = ft_strdup(temp);
	if (tag->dot && tag->precision >= 0)
		src = ft_substr(temp, 0, tag->precision);
	else
		src = ft_strdup(temp);
	count = ft_print_len(tag, src);
	free(temp);
	free(src);
	return (count);
}

int	ft_type_pointer(va_list ap, t_ftag *tag)
{
	char			*src;
	char			*temp;
	int				count;
	unsigned long	n;

	n = va_arg(ap, unsigned long);
	if (tag->dot && tag->precision == 0 && n == 0)
		temp = ft_strdup("");
	else
		temp = ft_itoa_l_base(n, "0123456789abcdef", tag);
	src = ft_strjoin("0x", temp);
	count = ft_print_len(tag, src);
	free(temp);
	free(src);
	return (count);
}
