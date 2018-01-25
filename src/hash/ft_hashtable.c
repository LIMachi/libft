/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 09:13:46 by hmartzol          #+#    #+#             */
/*   Updated: 2018/01/25 05:06:53 by hmartzol         ###   ########.fr       */
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

t_hashtable	ft_hashtable(size_t size,
						size_t (*hasher)(const char*, const size_t))
{
	if (size <= 0)
		return ((t_hashtable){.size = 0, .data = NULL, .hasher = NULL});
	return ((t_hashtable){
		.size = size,
		.data = ft_memalloc(size * sizeof(t_llist*)),
		.hasher = hasher
	});
}
