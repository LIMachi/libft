/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluate_u128_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lee <lee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 18:25:04 by lee               #+#    #+#             */
/*   Updated: 2017/02/25 18:25:28 by lee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_evaluate_u128_size(__uint128_t v)
{
	size_t		l;

	if (v == 0)
		return (1);
	l = 1;
	while (v /= 10)
		++l;
	return (l);
}
