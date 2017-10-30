/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memquicksort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 07:08:33 by hmartzol          #+#    #+#             */
/*   Updated: 2017/10/17 08:34:01 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void ft_memquicksort(void **data, int len, int (*cmp)(void *, void *))
{
	void	*pivot;
	int		i;
	int		j;
	void	*t;

	if (len < 2)
		return ;
	pivot = data[len / 2];
	i = 0;
	j = len - 1;
	while (1)
	{

		while (cmp(data[i], pivot) > 0)
			++i;
		while (cmp(data[j], pivot) < 0)
			--j;
		if (i >= j)
			break ;
		t = data[i];
		data[i++] = data[j];
		data[j--] = t;
	}
	ft_memquicksort(data + i, len - i, cmp);
	ft_memquicksort(data, i, cmp);
}
