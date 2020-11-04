#include "libft.h"
#include <stdio.h>
#include <string.h>

/*
**ft_memmove
*/
void	test_memmove(void)
{
	char array[10];

    ft_memset(array, 0, sizeof(array));
    strcpy(array, "test");

    printf("=====test_memmove=====\n");
    printf("original : %s\n", array);

	ft_memmove(array+2, array, ft_strlen("test"));

    printf("after memmove : %s\n", array);
}

/*
** ft_strjoin
*/
void	test_strjoin(void)
{
	char *a = "hello ";
	char *b = "goodbye";
	char *joined;

	joined = ft_strjoin(a, b);
	printf("=====test_strjoin=====\n");
	printf("joined : %s,  %s %s\n", joined, a, b);
}

/*
** ft_strlcat
*/
void	test_strlcat(void)
{
	printf("=====test_strlcat=====\n");
	char src[] = "saysomthing";
	char dst[10] = "goods";
	printf("return (5+11) : %zu, dst(goodssay) : %s\n", ft_strlcat(dst,src,9), dst);
	//printf("return (5+11) : %u, dst(goodssay) : %s\n", strlcat(dst,src,9), dst);
}
/*
**ft_strtrim
*/
void	test_strtrim(void)
{
	char *text = "_!ABCDEFG#";
	char *set = "#A!_\0";

	char *res = ft_strtrim(text, set);
	printf("=====test_strtrim=====\n");
	printf("%s\n", res);
}

/*
**ft_split
*/
int test_split(void)
{
	char *s1 = "The.Little.Prince";
	char c = '.';
	char **result = ft_split(s1, c);
	printf("split result = %p\n", result);
	for (int i = 0; result[i]; ++i) {
		printf("%d -> %s\n", i, result[i]);
		free(result[i]);
	}
	free(result);
	result = 0;
	printf("==\n");
	result = ft_split("cabcde", 'c');
	printf("split result = %p\n", result);
	for (int i = 0; result[i]; ++i) {
		printf("%d -> %s\n", i, result[i]);
		free(result[i]);
	}
	free(result);
	result = 0;
	printf("==\n");
	result = ft_split("cccc", 'c');
	printf("split result = %p\n", result);
	for (int i = 0; result[i]; ++i) {
		printf("%d -> %s\n", i, result[i]);
		free(result[i]);
	}
	free(result);
	result = 0;
	printf("==\n");
	result = ft_split("The Little Prince", ' ');
	printf("split result = %p\n", result);
	for (int i = 0; result[i]; ++i) {
		printf("%d -> %s\n", i, result[i]);
		free(result[i]);
	}
	free(result);
	result = 0;
	printf("==\n");
	return (1);
}

/*
**ft_itoa
*/
void	test_itoa(void)
{
	printf("=====test_itoa=====\n");
	int s = 0;
	char *result = ft_itoa(s);
	printf("%d, %s\n", s, result);

	s = 1;
	result = ft_itoa(s);
	printf("%d, %s\n", s, result);

	s = INT_MAX;
	result = ft_itoa(s);
	printf("%d, %s\n", s, result);

	s = INT_MIN;
	result = ft_itoa(s);
	printf("%d, %s\n", s, result);
}

/*
**ft_putnbr_fd
*/
void	test_putnbr_fd(void)
{
	printf("=====test_putnbr_fd=====\n");
	ft_putnbr_fd(152,1);
	ft_putnbr_fd(-152,1);
	ft_putnbr_fd(-2147483648,1);
}
int		main(void)
{
	/*
	**ft_memmove
	*/
	test_memmove();

	/*
	** ft_strjoin
	*/
	test_strjoin();

	/*
	** ft_strlcat
	*/
	test_strlcat();

	/*
	**ft_strtrim
	*/
	test_strtrim();

	/*
	**ft_split
	*/
	test_split();

	/*
	**ft_itoa
	*/
	test_itoa();
	/*
	**ft_putnbr_fd
	*/
	test_putnbr_fd();
}
