/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 07:41:53 by hmartzol          #+#    #+#             */
/*   Updated: 2017/10/17 08:34:33 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void ft_quicksort(int *data, int len)
{
	int		pivot;
	int		i;
	int		j;
	int		t;

	if (len < 2)
		return ;
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
}
