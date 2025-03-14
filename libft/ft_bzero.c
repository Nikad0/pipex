/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:12:06 by erbuffet          #+#    #+#             */
/*   Updated: 2024/11/22 10:17:31 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp_s;
	size_t			i;

	temp_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		temp_s[i] = 0;
		i++;
	}
}
