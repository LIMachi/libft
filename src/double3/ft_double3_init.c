/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double3_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2016/10/09 08:38:42 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_double3		*ft_double3_init(t_double3 *vector, const double x,
	const double y, const double z)
{
	if (vector != NULL)
		*vector = (t_double3){.x = x, .y = y, .z = z};
	return (vector);
}
