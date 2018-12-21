/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flat_hash_map_expand.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2018/01/29 04:48:29 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_flat_hash_map.h>

int					ft_flat_hash_map_expand(t_fhm_map *map, int factor)
{
	t_fhm_map		tmp;
	size_t			i;
	int				match;
	int				j;

	tmp = (t_fhm_map){.pair_count = 0, .nb_groups = map->nb_groups * factor,
		.hashfun = map->hashfun, .cmpfun = map->cmpfun,
		.groups = malloc(sizeof(t_fhm_group) * map->nb_groups * factor)};
	if (tmp.groups == NULL)
		return (-1);
	i = -1;
	while (++i < map->nb_groups)
	{
		match = _mm_movemask_epi8(map->groups[i].control);
		j = -1;
		while (++j < 16)
			if (match & (1 << i))
				if (__builtin_expect(
					ft_flat_hash_map_insert(&tmp, map->groups[i].slot[j].key,
						map->groups[i].slot[j].data), 0))
					return (-1);
	}
	ft_flat_hash_map_destroy(map);
	*map = tmp;
	return (0);
}
