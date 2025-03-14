/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:50:01 by erbuffet          #+#    #+#             */
/*   Updated: 2024/11/22 21:23:09 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	temp_c;
	unsigned char	*temp_s;
	size_t			i;

	temp_c = (unsigned char)c;
	temp_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (temp_s[i] == temp_c)
			return ((void *)(&temp_s[i]));
		i++;
	}
	return (0);
}
