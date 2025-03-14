/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:23:55 by erbuffet          #+#    #+#             */
/*   Updated: 2024/11/25 13:16:44 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	int		i;
	char	*tab;

	i = 0;
	tab = malloc(nmemb * size);
	if (!tab)
		return (NULL);
	if (nmemb > 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	while (tab[i])
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
