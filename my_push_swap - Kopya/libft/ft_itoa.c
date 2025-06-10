/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:28:08 by mdinc             #+#    #+#             */
/*   Updated: 2024/11/08 13:28:08 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	d_count(int nbr)
{
	int	nbr_len;

	nbr_len = 0;
	if (nbr <= 0)
		nbr_len++;
	while (nbr)
	{
		nbr /= 10;
		nbr_len++;
	}
	return (nbr_len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digit;
	long	new;

	digit = d_count(n);
	new = n;
	str = (char *) ft_calloc(digit + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		*str = '0';
	else if (new < 0)
	{
		new = n;
		new *= -1;
		str[0] = '-';
	}
	while (new != 0)
	{
		digit--;
		str[digit] = (new % 10) + '0';
		new = new / 10;
	}
	return (str);
}
