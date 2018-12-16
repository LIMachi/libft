/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp_default.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 19:34:13 by hmartzol          #+#    #+#             */
/*   Updated: 2016/12/18 23:30:16 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_bmp	*ft_bmp_default(void)
{
	static char		data[sizeof(t_bmp) + sizeof(int) * 4] = {0};
	static t_bmp	*bmp = (t_bmp*)data;

	if (bmp->size.x == 0)
	{
		bmp->size.x = 2;
		bmp->size.y = 2;
		bmp->data[0] = 0;
		bmp->data[1] = 0xFF;
		bmp->data[2] = 0xFF00;
		bmp->data[3] = 0xFF0000;
	}
	return (bmp);
}
