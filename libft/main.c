#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	/*
	**ft_memmove
	*/
	char array[10];

    ft_memset(array, 0, sizeof(array));
    strcpy(array, "test");

    printf("original : %s\n", array);

	ft_memmove(array+2, array, ft_strlen("test"));

    printf("after memmove : %s\n", array);

	/*
	** ft_strjoin
	*/
	char *a = "hello ";
	char *b = "goodbye";
	char *joined;

	joined = ft_strjoin(a, b);
	printf("joined : %s,  %s %s", joined, a, b);

	/*
	** ft_strlcat
	*/
	char src[] = "saysomthing";
	char dst[10] = "goods";
	printf("return (5+11) : %zu, dst(goodssay) : %s\n", ft_strlcat(dst,src,9), dst);
	//printf("return (5+11) : %u, dst(goodssay) : %s\n", strlcat(dst,src,9), dst);

	/*
	**ft_strtrim
	*/
	char *text = "_!ABCDEFG#";
	char *set = "#A!_\0";

	char *res = ft_strtrim(text, set);
	printf("%s", res);
}
