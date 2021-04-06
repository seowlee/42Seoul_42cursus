/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowoo <seowoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 22:34:09 by seowoo            #+#    #+#             */
/*   Updated: 2021/04/06 19:49:58 by seowoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(t_ftag *tag)
{
	tag->minus = 0;
	tag->zero = 0;
	tag->width = 0;
	tag->dot = 0;
	tag->precision = 0;
	tag->type = 0;
	tag->padding = ' ';

}
int		ft_printf(const char *format, ...)
{
	va_list ap;
	t_ftag	tag;
	int		nbrCharacters;

	va_start(ap, format);
	ft_init(&tag);
	nbrCharacters = 0;
	while (*format)
	{
		if(*format != '%')
		{
			ft_putchar_fd(*format++, 1);
			nbrCharacters++;
			continue;
		}
		format++;
		nbrCharacters += ft_parse(&format, ap, &tag);
		format++;
		ft_init(&tag);
	}
	va_end(ap);
	return (nbrCharacters);
}

#include <stdio.h>

int main(){
	printf("printf : %c\n", 'a');
	ft_printf("ft_printf : %c", 'a');
}

