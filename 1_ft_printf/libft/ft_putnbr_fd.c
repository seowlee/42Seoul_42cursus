/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowlee <seowlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 00:34:05 by seowlee           #+#    #+#             */
/*   Updated: 2020/10/31 10:04:32 by seowlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	whole_num_to_char(int n, int fd)
{
	if (n > 9)
	{
		whole_num_to_char(n / 10, fd);
		whole_num_to_char(n % 10, fd);
	}
	else if (n >= 0)
	{
		n += '0';
		write(fd, &n, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	whole_num_to_char(n, fd);
}
