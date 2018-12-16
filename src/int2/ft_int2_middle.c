/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int2_middle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 18:10:03 by hmartzol          #+#    #+#             */
/*   Updated: 2016/11/01 16:04:53 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_int2	ft_int2_middle(const t_int2 a, const t_int2 b)
{
	return ((t_int2){(b.x + a.x) / 2, (b.y + a.y) / 2});
}
