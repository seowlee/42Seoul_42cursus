/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowoo <seowoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:55:26 by seowoo            #+#    #+#             */
/*   Updated: 2021/04/06 16:23:27 by seowoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_iter_putchar_fd(char c, int fd, int len)
{
	while (len-- > 0)
		ft_putchar_fd(c, fd);
}

int		ft_print_len(t_ftag *tag, char *src)
{
	int count;
	int ws_len;

	count = ft_strlen(src);
	ws_len = tag->width - count;
	if (ws_len > 0)
	{
		count += ws_len;
		if (tag->minus)
		{
			ft_putstr_fd(src, 1);
			ft_iter_putchar_fd(tag->padding, 1, ws_len);
		}
		else
		{
			if (src[0] == '-' && tag->padding == '0')
				ft_putchar_fd(*src++, 1);
			ft_iter_putchar_fd(tag->padding, 1, ws_len);
			ft_putstr_fd(src, 1);
		}
	}
	else
		ft_putstr_fd(src, 1);
	return (count);
}
