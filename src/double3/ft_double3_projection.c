/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double3_projection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2016/10/24 20:40:25 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_double3		ft_double3_projection(const t_double3 a, const t_double3 b)
{
	t_double3	t;

	if (b.x == 0 && b.y == 0 && b.z == 0)
		t = b;
	else
		t = ft_double3_scale(b, (ft_double3_dot_product(a, b) /
			(b.x * b.x + b.y * b.y + b.z * b.z)));
	return (ft_double3_substract(a, t));
}
