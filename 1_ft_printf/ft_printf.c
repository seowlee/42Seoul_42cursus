#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		nbrCharacters;

	va_start(ap, format);
	while (*format)
	{
		if(*format != '%')
			;
		else
		{

		}

	}
	return (nbrCharacters);

}
