/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowlee <seowlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:00:25 by seowlee           #+#    #+#             */
/*   Updated: 2020/10/30 01:38:13 by seowlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_begin_idx(char const *s1, char const *set, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static size_t	get_end_idx(char const *s1, char const *set, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && ft_strchr(set, s1[len - 1 - i]))
		i++;
	return (len - i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;
	char	*result;
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	begin = get_begin_idx(s1, set, len);
	end = get_end_idx(s1, set, len);
	if (begin > end)
		return (ft_strdup(""));
	result = (char *)malloc(sizeof(char) * (end - begin + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + begin, end - begin + 1);
	return (result);
}
