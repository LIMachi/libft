/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flat_hash_map_find.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2018/01/29 04:48:29 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_flat_hash_map.h>

/*
** quick overview of SSE2 calls:
** _mm_set1_epi8 -> bytes1[16]{H2(hash)}
** _mmcmpeq_epi8 -> cmp(bytes1[16], bytes2[16])->bytes3[16] (m: 0xFF, f: 0x00)
** _mm_movemask_epi8 -> bytes3[16] -> bytes[2] (0xFF -> 1, 0x00 -> 0)
** basically, given a meta 96, will find in a group of 16 meta all that match 96
** and represent the match in a 16 bit mask
** 7F,DF,96,32,F1,F8,EB,43,7F,DF,96,32,F1,F8,EB,43 _ 96 -> 0b0010000000100000
*/

void	*ft_flat_hash_map_find(t_fhm_map *map, void *key)
{
	t_fhm_hash		hash;
	size_t			gi;
	int				i;
	t_fhm_group		g;
	int				match;

	hash.s = map->hashfun(key, map->nb_groups << 4);
	gi = hash.h.position % map->nb_groups;
	while (1)
	{
		g = map->groups[gi];
		match = _mm_movemask_epi8(_mm_cmpeq_epi8(_mm_set1_epi8(
			hash.h.meta), g.control));
		i = -1;
		while (++i < 16)
			if (match & (1 << i)
					&& __builtin_expect(!map->cmpfun(g.key[i], key), 1))
				return (map->values[gi * 16 + i]);
		if (__builtin_expect(match != 0b1111111111111111, 1))
			return (NULL);
		gi = (gi + 1) % map->nb_groups;
	}
}
