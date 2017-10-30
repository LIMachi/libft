/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 01:06:30 by hmartzol          #+#    #+#             */
/*   Updated: 2017/10/17 01:16:50 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

int	ft_eval_int_ll(unsigned long long v)
{
	return (!(v & SMASK) ^ !!(v & SLLMASK));
}
