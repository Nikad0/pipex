/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:02:36 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/12 21:54:39 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**free_all(char **array);
size_t	ft_count_word(const char *s, char c);
size_t	word_len(char const *s, size_t i, char c);

char	**ft_split(const char *s, char c)
{
	char	**array;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	array = malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (j < ft_count_word(s, c))
	{
		while (s[i] == c)
			i++;
		array[j] = ft_substr(s, i, word_len(s, i, c));
		if (!array[j])
			return (free_all(array));
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	array[j] = NULL;
	return (array);
}

size_t	ft_count_word(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = -1;
	count = 0;
	while (s[++i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i + 1] == '\0' && s[i] != c))
			count++;
	}
	return (count);
}

char	**free_all(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	return (NULL);
}

size_t	word_len(char const *s, size_t i, char c)
{
	size_t	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}
