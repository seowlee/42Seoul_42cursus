#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>

typedef struct s_ftag
{
	int	left;
	int zero;
	int precision;
	int width;
}				t_ftag;

int		ft_printf(const char *format, ...);
#endif
