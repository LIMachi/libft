/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 07:41:53 by hmartzol          #+#    #+#             */
/*   Updated: 2018/01/16 18:44:04 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int64_t		*ft_quicksort(int64_t *data, int64_t len)
{
	int64_t		pivot;
	int64_t		i;
	int64_t		j;
	int64_t		t;

	if (len < 2)
		return (data);
	pivot = data[len / 2];
	i = 0;
	j = len - 1;
	while (1)
	{
		while (data[i] < pivot)
			++i;
		while (data[j] > pivot)
			--j;
		if (i >= j)
			break ;
		t = data[i];
		data[i++] = data[j];
		data[j--] = t;
	}
	ft_quicksort(data + i, len - i);
	ft_quicksort(data, i);
	return (data);
}
