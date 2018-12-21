/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flat_hash_map_iterate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2018/01/29 04:48:29 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_flat_hash_map.h>
#include <stdio.h>

/*
** usage example (with keys and values being null terminated strings):
** char *key;
** char *value;
** size_t it = 0;
** while (ft_flat_hash_map_iterate(map, &it, (void**)&key, (void**)&value) == 1)
**   printf("'%s': '%s'\n", key, value);
*/

int	ft_flat_hash_map_iterate(t_fhm_map *map,
		size_t *it,
		void **key_retriever,
		void **value_retriever)
{
	t_fhm_group	g;
	int			i;
	int			match;

	while (*it < map->nb_groups << 4)
	{
		g = map->groups[*it >> 4];
		match = _mm_movemask_epi8(g.control);
		i = *it & 0xF;
		while (i < 0x10 && match & (1 << i))
			++i;
		if (i != 0x10)
		{
			*it = (*it & ~0xF) | i;
			*key_retriever = g.key[i];
			*value_retriever = map->values[*it];
			++*it;
			return (1);
		}
		*it = (*it & ~0xF) + 0x10;
	}
	return (*it == map->nb_groups << 4 ? 0 : -1);
}
