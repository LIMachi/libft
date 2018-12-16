/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_multply_vector_array.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 11:00:59 by hmartzol          #+#    #+#             */
/*   Updated: 2016/11/02 11:20:44 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_double3		*ft_matrix_multply_vector_array(t_double3 *va, size_t size,
													const t_matrix *m)
{
	t_double3	v;

	if (m == NULL || va == NULL || size == 0)
		return (NULL);
	if (m->size.x != 3 || m->size.y != 3)
		return (NULL);
	while (size--)
	{
		v = va[size];
		va[size] = (t_double3){
			.x = v.x * m->mat[0][0] + v.y * m->mat[0][1] + v.z * m->mat[0][2],
			.y = v.x * m->mat[1][0] + v.y * m->mat[1][1] + v.z * m->mat[1][2],
			.z = v.x * m->mat[2][0] + v.y * m->mat[2][1] + v.z * m->mat[2][2]};
	}
	return (va);
}
