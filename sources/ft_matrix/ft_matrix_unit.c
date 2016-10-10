/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_unit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by hmartzol          #+#    #+#             */
/*   Updated: 2016/10/09 08:59:56 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_matrix	*ft_matrix_unit(const int size)
{
	t_matrix	*out;
	t_point		pos;

	if (size < 1 || (out = (t_matrix*)malloc(sizeof(t_matrix))) == NULL)
		return (NULL);
	if ((out->mat = (double**)ft_taballoc(size, size, sizeof(double))) == NULL)
	{
		free(out);
		return (NULL);
	}
	out->size.x = size;
	out->size.y = size;
	pos.y = -1;
	while (++pos.y < size && (pos.x = -1))
		while (++pos.x < size)
			out->mat[pos.y][pos.x] = pos.x == pos.y;
	return (out);
}
