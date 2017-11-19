/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 01:06:30 by hmartzol          #+#    #+#             */
/*   Updated: 2017/11/03 18:23:47 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_int.h>
#include <stdio.h>

int	ft_eval_int_ll(unsigned long long v)
{
	return (!(v & SMASK) ^ !!(v & SLLMASK));
}

int	ft_eval_int_size(int v)
{
	int i;

	i = 1;
	if (v < 0)
	{
		v = -(v + v == INTMIN);
		++i;
	}
	while (v /= 10)
		++i;
	return (i);
}
