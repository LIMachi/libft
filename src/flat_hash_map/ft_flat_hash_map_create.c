/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flat_hash_map_create.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2018/01/29 04:48:29 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_flat_hash_map.h>

t_fhm_map	ft_flat_hash_map_create(t_fhm_hashfun hash,
											t_fhm_cmpfun cmp)
{
	t_fhm_map	out;
	size_t		i;

	out = (t_fhm_map){.pair_count = 0, .nb_groups = FHM_BASE_SIZE,
		.hashfun = hash, .cmpfun = cmp,
		.groups = malloc(sizeof(t_fhm_group) * FHM_BASE_SIZE),
		.values = malloc(sizeof(void*) * FHM_BASE_SIZE)};
	if (out.groups == NULL || out.values == NULL)
	{
		free(out.groups);
		free(out.values);
		out = (t_fhm_map){.groups = NULL, .nb_groups = 0, .cmpfun = NULL,
			.hashfun = NULL, .pair_count = 0};
		return (out);
	}
	i = -1;
	while (++i < out.nb_groups)
		out.groups[i].control = _mm_set1_epi8((char)FHM_EMPTY);
	return (out);
}
