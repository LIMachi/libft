/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flat_hash_map_delete.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2018/01/29 04:48:29 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_flat_hash_map.h>

void	*ft_flat_hash_map_delete(t_fhm_map *map, void *key)
{
	t_fhm_hash		hash;
	size_t			gi;
	int				i;
	t_fhm_group		g;
	int				match;

	hash.s = map->hashfun(key, map->nb_groups << 4);
	gi = hash.h.position % map->nb_groups;
	while ((i = -1))
	{
		g = map->groups[gi];
		match = _mm_movemask_epi8(_mm_cmpeq_epi8(_mm_set1_epi8(
				hash.h.meta), g.control));
		while (++i < 16)
			if (match & (1 << i)
				&& __builtin_expect(!map->cmpfun(g.key[i], key), 1))
			{
				map->groups[gi].control &= ~(I1280XFF << (i << 8));
				map->groups[gi].control |= I128DEL << (i << 8);
				return (map->values[gi * 16 + i]);
			}
		if (__builtin_expect(match != 0b1111111111111111, 1))
			return (NULL);
		gi = (gi + 1) % map->nb_groups;
	}
}
