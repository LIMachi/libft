/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flat_hash_map_clear.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2018/01/29 04:48:29 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_flat_hash_map.h>

/*
** iterate over the map and replace all FHM_DELETED with FHM_EMPTY and reduce
** map->pair_count by the amount of 'emptied' slots
*/

int	ft_flat_hash_map_clear(t_fhm_map *map)
{
	(void)map;
	/*
	size_t		i;
	int			mmatch;
	__m128i		control;
	__m128i		match;

	i = -1;
	while (++i < map->nb_groups)
	{
		control = map->groups[i].control;
		match = _mm_cmpeq_epi8(_mm_set1_epi8((char)FHM_DELETED), control);
		control &= ~match;
		control |= match & _mm_set1_epi8((char)FHM_EMPTY);
		map->groups[i].control = control;
		mmatch = _mm_movemask_epi8(match);
		while (mmatch)
		{
			if (mmatch & 1)
				--map->pair_count;
			mmatch >>= 1;
		}
	}*/
	return (0);
}
