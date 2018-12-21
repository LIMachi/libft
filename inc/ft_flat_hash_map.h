/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flat_hash_map.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2018/01/29 04:48:29 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** addapted from: https://www.youtube.com/watch?v=ncHmEUmJZf4
*/

#ifndef FT_FLAT_HASH_MAP_H
# define FT_FLAT_HASH_MAP_H

# include <stddef.h>

# if (!defined(__SIZEOF_SIZE_T__) || __SIZEOF_SIZE_T__ < 2)
#  error "invalid/missing __SIZEOF_SIZE_T__"
# endif

# ifdef __SSE2__
#  include <emmintrin.h>
# else
#  error "missing SSE2 processor instructions"
# endif

# define FHM_BASE_SIZE (16)

# define FHM_LOAD_FACTOR (0.75)

# define FHM_EXPAND_FACTOR (2)

typedef enum		e_fhm_control
{
	FHM_EMPTY = 0b10000000,
	FHM_DELETED = 0b11111110,
	FHM_SENTINEL = 0b11111111,
	FHM_FULL_MASK = 0b01111111
}					t_fhm_control;

typedef struct		s_fhm_pair
{
	void			*key;
	void			*data;
}					t_fhm_pair;

/*
** __m128i control -> t_fhm_control(char)[16]
*/

typedef struct		s_fhm_group
{
	__m128i			control;
	t_fhm_pair		slot[16];
}					t_fhm_group;

struct				s_fhm_hash
{
	char			meta : 7;
	size_t			position : (__SIZEOF_SIZE_T__ << 3) - 7;
};

typedef union		u_fhm_hash
{
	struct s_fhm_hash	h;
	size_t				s;
}					t_fhm_hash;

typedef int			(*t_fhm_cmpfun)(void *, void *);

typedef size_t		(*t_fhm_hashfun)(void *, size_t);

typedef struct		s_fhm_map
{
	size_t			nb_groups;
	size_t			pair_count;
	t_fhm_cmpfun	cmpfun;
	t_fhm_hashfun	hashfun;
	t_fhm_group		*groups;
}					t_fhm_map;

t_fhm_map			ft_flat_hash_map_create(t_fhm_hashfun hash,
											t_fhm_cmpfun cmp);

int					ft_flat_hash_map_insert(t_fhm_map *map,
											void *key,
											void *value);

int					ft_flat_hash_map_expand(t_fhm_map *map, int factor);

void				*ft_flat_hash_map_find(t_fhm_map *map, void *key);

void				*ft_flat_hash_map_delete(t_fhm_map *map, void *key);

void				ft_flat_hash_map_destroy(t_fhm_map *map);

size_t				ft_basic_hash(char *str, size_t tab_size);

#endif
