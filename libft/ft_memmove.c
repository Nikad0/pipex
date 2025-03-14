/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:38:46 by erbuffet          #+#    #+#             */
/*   Updated: 2024/11/22 21:23:25 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	unsigned char	*temp_destination;
	unsigned char	*temp_source;
	size_t			i;

	temp_destination = (unsigned char *)destination;
	temp_source = (unsigned char *)source;
	i = 0;
	if ((temp_destination == 0) && (temp_source == 0))
		return (0);
	if (temp_destination > temp_source && temp_destination <= temp_source + n)
	{
		while (n-- > 0)
			temp_destination[n] = temp_source[n];
	}
	else
	{
		while (i < n)
		{
			temp_destination[i] = temp_source[i];
			i++;
		}
	}
	return (destination);
}
