/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memindexes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 08:37:24 by hmartzol          #+#    #+#             */
/*   Updated: 2017/10/17 08:44:38 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	*ft_memindexes(void **data, void **order,
						int (*equal)(void *a, void *b), size_t size)
{
	size_t	*out;
	size_t	i;
	size_t	j;

	if ((out = (size_t*)ft_memalloc(size * sizeof(size_t))) == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			if (equal(data[i], order[j]))
			{
				out[i] = j;
				break ;
			}
		if (j == size)
		{
			ft_free(out);
			return (NULL);
		}
	}
	return (out);
}
