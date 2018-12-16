/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double3_angle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2016/10/24 21:22:47 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

double			ft_double3_angle(const t_double3 a, const t_double3 b)
{
	double	vec_a_mag;

	vec_a_mag = ft_double3_magnitude(a);
	if (vec_a_mag == 0)
		return (INFINITY);
	return (ft_acos(ft_double3_dot_product(a, b) / (vec_a_mag * vec_a_mag)));
}
