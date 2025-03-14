/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:35:19 by erbuffet          #+#    #+#             */
/*   Updated: 2024/11/22 21:24:23 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicata;
	int		i;

	duplicata = NULL;
	i = 0;
	duplicata = malloc(ft_strlen(s) + 1);
	if (!duplicata)
		return (NULL);
	while (s[i])
	{
		duplicata[i] = s[i];
		i++;
	}
	duplicata[i] = '\0';
	return (duplicata);
}
