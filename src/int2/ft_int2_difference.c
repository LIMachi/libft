/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int2_difference.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 09:05:19 by hmartzol          #+#    #+#             */
/*   Updated: 2016/10/14 14:10:26 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_int2	ft_int2_difference(const t_int2 a, const t_int2 b)
{
	return ((t_int2){.x = ABS(a.x - b.x), .y = ABS(a.y - b.y)});
}
