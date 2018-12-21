/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:57:14 by hmartzol          #+#    #+#             */
/*   Updated: 2017/03/09 21:57:25 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_flat_hash_map.h>
#include <stdio.h>

int	main(void)
{
	t_fhm_map	map;
	size_t		it;
	char		*key;
	char		*data;

	map = ft_flat_hash_map_create((t_fhm_hashfun)ft_basic_hash,
		(t_fhm_cmpfun)ft_strcmp);
	ft_flat_hash_map_insert(&map, "test", "1");
	ft_flat_hash_map_insert(&map, "testsak", "2");
	ft_flat_hash_map_insert(&map, "cool", "3");
	data = ft_flat_hash_map_find(&map, "testsak");
	printf("data: '%s'\n", data);
	printf("iterate:\n");
	it = 0;
	while (ft_flat_hash_map_iterate(&map, &it, (void**)&key,
			(void**)&data) == 1)
		printf("%zu '%s': '%s'\n", it, key, data);
	ft_flat_hash_map_delete(&map, "cool");
	ft_flat_hash_map_clear(&map);
	printf("pair_count: %zu\n", map.pair_count);
	it = 0;
	while (ft_flat_hash_map_iterate(&map, &it, (void**)&key,
									(void**)&data) == 1)
		printf("%zu '%s': '%s'\n", it, key, data);
	ft_flat_hash_map_destroy(&map);
	return (0);
}
