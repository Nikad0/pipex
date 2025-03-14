/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 09:31:02 by erbuffet          #+#    #+#             */
/*   Updated: 2024/11/24 15:59:42 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	n_size(long int numbr)
{
	int	size;

	size = 1;
	while (numbr)
	{
		numbr /= 10;
		if (numbr)
			size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long int	numbr;
	int			size;
	char		*nb;

	numbr = n;
	size = n_size(numbr);
	if (numbr < 0)
	{
		numbr *= -1;
		size++;
	}
	nb = malloc(size + 1);
	if (!nb)
		return (NULL);
	nb[size] = 0;
	while (size--)
	{
		nb[size] = (numbr % 10) + '0';
		numbr /= 10;
	}
	if (n < 0)
		nb[0] = '-';
	nb[size] = '\0';
	return (nb);
}
