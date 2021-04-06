/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowlee <seowlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:38:21 by seowlee           #+#    #+#             */
/*   Updated: 2020/11/04 12:01:54 by seowlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		num_w(char const *s, char c)
{
	int	i;
	int n_word;

	i = 0;
	n_word = 0;
	while (s[i])
	{
		if (s[i] != c)
			n_word++;
		while (s[i] != c && s[i + 1])
			i++;
		i++;
	}
	return (n_word);
}

static int		get_len_word(char const *s, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static int		get_idx_cpy_word(char const *s, char c, char *result)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (s[j] == c)
		j++;
	while (s[j] != c && s[j])
		result[k++] = s[j++];
	result[k] = '\0';
	return (j);
}

static char		**free_malloc(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	if ((result = (char **)malloc(sizeof(char *) * (num_w(s, c) + 1))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < num_w(s, c))
	{
		if (s[j])
		{
			result[i] =
				(char *)malloc(sizeof(char) * (get_len_word(&s[j], c) + 1));
			if (result[i] == NULL)
				return (free_malloc(result));
			j += get_idx_cpy_word(&s[j], c, result[i]);
			i++;
		}
	}
	result[i] = 0;
	return (result);
}
