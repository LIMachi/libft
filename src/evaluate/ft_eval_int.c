/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 01:06:30 by hmartzol          #+#    #+#             */
/*   Updated: 2018/01/17 22:40:14 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_int.h>
#include <stdio.h>

int	ft_eval_int_ll(unsigned long long v)
{
	if (v == 0)
		return (1);
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
