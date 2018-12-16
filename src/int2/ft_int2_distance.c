/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int2_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 09:05:19 by hmartzol          #+#    #+#             */
/*   Updated: 2016/10/14 14:10:28 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

double	ft_int2_distance(const t_int2 a, const t_int2 b)
{
	return (ft_int2_magnitude(ft_int2_substract(a, b)));
}
