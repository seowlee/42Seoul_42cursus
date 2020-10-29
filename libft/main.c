#include "libft.h"
#include <stdio.h>

int main(void)
{
	/*
	** ft_strjoin
	*/
	char *a = "hello ";
	char *b = "goodbye";
	char *joined;

	joined = ft_strjoin(a, b);
	printf("joined : %s,  %s %s", joined, a, b);

	/*
	**ft_strtrim
	*/
	char *text = "_!ABCDEFG#";
	char *set = "#A!_\0";

	char *res = ft_strtrim(text, set);
	printf("%s", res);
}
