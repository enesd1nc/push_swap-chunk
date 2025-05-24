/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:32:31 by mdinc             #+#    #+#             */
/*   Updated: 2025/05/24 15:39:38 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_chunk_size(int size)
{
	int	chunk_size;

	if (size <= 100)
		chunk_size = size / 5;
	else if (size <= 250)
		chunk_size = size / 8;
	else if (size <= 500)
		chunk_size = (size / 13) - 2;
	else
		chunk_size = size / 14;
	return (chunk_size);
}
