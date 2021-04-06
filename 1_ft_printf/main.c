#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int i = 12345;
	printf("printf i : %.7d \n", i);
	ft_printf("ft i : %.7d \n", i);

	printf("printf %*c \n", -5, 'a');
	ft_printf("ftprin %*c \n", -5, 'a');

	printf("printf %s \n", "abcde");
	ft_printf("ftprin %s\n", "abcde");
	printf("printf %s \n", NULL);
	ft_printf("ftprin %s \n", NULL);

	printf("printf %7u \n", 12345);
	ft_printf("ftprin %7u \n", 12345);

	printf("printf %3x \n", 768955);
	ft_printf("ftprin %3x\n", 768955);
	printf("printf %7x \n", 768955);
	ft_printf("ftprin %7x \n", 768955);

	printf("printf %5% \n");
	ft_printf("ftprin %5%\n");
}