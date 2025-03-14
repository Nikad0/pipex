/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:54:57 by erbuffet          #+#    #+#             */
/*   Updated: 2024/11/23 08:57:46 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len_s;

	len_s = ft_strlen(s);
	while (len_s >= 0)
	{
		if (s[len_s] == (unsigned char)c)
			return ((char *)(s + len_s));
		len_s--;
	}
	return (0);
}
