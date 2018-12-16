/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double3_from_a_to_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 16:05:53 by hmartzol          #+#    #+#             */
/*   Updated: 2016/11/01 16:06:25 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_double3		ft_double3_from_a_to_b(t_double3 a, t_double3 b)
{
	return (ft_double3_substract(b, a));
}
