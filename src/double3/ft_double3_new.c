/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double3_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2016/12/19 00:50:00 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_double3		*ft_double3_new(const double x, const double y, const double z)
{
	t_double3	*out;

	if ((out = (t_double3*)ft_malloc(sizeof(t_double3))) == NULL)
		return (NULL);
	out->x = x;
	out->y = y;
	out->z = z;
	return (out);
}
