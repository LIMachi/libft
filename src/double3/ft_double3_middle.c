/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double3_middle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2016/11/01 16:01:40 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_double3	ft_double3_middle(const t_double3 a, const t_double3 b)
{
	return ((t_double3){(b.x + a.x) / 2, (b.y + a.y) / 2, (b.z + a.z) / 2});
}
