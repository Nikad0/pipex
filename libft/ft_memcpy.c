/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:20:47 by erbuffet          #+#    #+#             */
/*   Updated: 2024/11/22 14:50:20 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dest;
	size_t			i;

	temp_src = (unsigned char *)src;
	temp_dest = (unsigned char *)dest;
	i = 0;
	if ((temp_dest == 0) && (temp_src == 0))
		return (0);
	while (i < n)
	{
		temp_dest[i] = temp_src[i];
		i++;
	}
	return (dest);
}
