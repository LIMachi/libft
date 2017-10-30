/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 09:13:46 by hmartzol          #+#    #+#             */
/*   Updated: 2017/10/23 09:46:55 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** to test if the hashtable returned is valid, use the data pointer of returned
** hashtable: if it's NULL, then an error occured
** example of securisation of this function call (note: hasher CAN be NULL):
** t_hashtable	table;
** if ((table = ft_hashtable(SIZE, NULL)).data == NULL)
**  exit(ERROR);
*/

t_hashtable	ft_hashtable(size_t size, size_t (*hasher)(char*, size_t))
{
	if (size <= 0)
		return ((t_hashtable){
			.size = 0,
			.data = NULL,
			.asher = NULL
		});
	return ((t_hashtable){
		.size = size,
		.data = ft_memalloc(size * sizeof(*t_list)),
		.asher = asher
	});
}
