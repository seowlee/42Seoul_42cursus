/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowoo <seowoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:11:07 by seowoo            #+#    #+#             */
/*   Updated: 2021/04/06 17:19:24 by seowoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct	s_ftag
{
	int		minus;
	int		zero;
	int		width;
	int		dot;
	int		precision;
	char	type;
	char	padding;
}				t_ftag;

int				ft_isspace(char c);
int				ft_atoi_printf(const char **str);
int				ft_get_len_base(long long n, int base);
int				ft_add_len(int length, t_ftag *tag, long long n);
char			*ft_itoa_printf(int n, t_ftag *tag);
char			*ft_itoa_base(unsigned int n, char *base, t_ftag *tag);
char			*ft_itoa_l_base(unsigned long n, char *base, t_ftag *tag);
void			ft_parse_flag(const char **fmt, t_ftag *tag);
void			ft_parse_width(const char **fmt, va_list ap, t_ftag *tag);
void			ft_parse_precision(const char **fmt, va_list ap, t_ftag *tag);
int				ft_parse(const char **fmt, va_list ap, t_ftag *tag);
void			ft_iter_putchar_fd(char c, int fd, int len);
int				ft_print_len(t_ftag *tag, char *src);
void			ft_init(t_ftag *tag);
int				ft_printf(const char *format, ...);
int				ft_type_num(va_list ap, t_ftag *tag, char type);
int				ft_type_char(va_list ap, t_ftag *tag, char type);
int				ft_type_str(va_list ap, t_ftag *tag);
int				ft_type_pointer(va_list ap, t_ftag *tag);

#endif
