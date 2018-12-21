/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flat_hash_map_insert.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2018/01/29 04:48:29 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_flat_hash_map.h>

int	ft_flat_hash_map_insert(t_fhm_map *map, void *key, void *value)
{
	t_fhm_hash	hash;
	size_t		gi;
	int			i;
	int			match;

	if (map->pair_count >= FHM_LOAD_FACTOR * map->nb_groups * 16)
		if (ft_flat_hash_map_expand(map, FHM_EXPAND_FACTOR))
			return (-1);
	hash.s = map->hashfun(key, map->nb_groups << 4);
	gi = hash.h.position % map->nb_groups;
	while (1)
	{
		if ((match = _mm_movemask_epi8(_mm_cmpeq_epi8(_mm_set1_epi8(
				(char)FHM_EMPTY), map->groups[gi].control))) && !(i = 0))
			while (i < 16)
				if (match & (1 << i++))
				{
					((char *)&map->groups[gi].control)[i - 1] = hash.h.meta;
					map->groups[gi].key[i - 1] = key;
					map->values[gi * 16 + i - 1] = value;
					++map->pair_count;
					return (0);
				}
		gi = (gi + 1) % map->nb_groups;
	}
}
