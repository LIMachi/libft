/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_insert.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 09:25:27 by hmartzol          #+#    #+#             */
/*   Updated: 2017/10/30 16:35:54 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** self explanatory, insert a node similar to a t_list in the hashtable using
** label as the index (once hashed by the hasher function)
** return the index in which the node was inserted, -1 significate an error
*/

size_t			ft_hashtable_insert(t_hashtable *table,
									char *label, void *data, size_t data_size)
{
	size_t	index;
	t_llist	*node;

	if (table == NULL || label == NULL || table->data == NULL)
		return (-1);
	if (table->hasher != NULL)
		index = table->hasher(label, table->size);
	else
		index = ft_default_hasher(label, table->size);
	if (index >= table->size)
		return (-1);
	if ((node = ft_malloc(sizeof(t_llist))) == NULL)
		return (-1);
	*node = (t_llist){.data = data, .next = NULL, .data_size = data_size,
					.label = label};
	ft_lstadd((t_list**)&table->data[index], (t_list*)node);
	return (index);
}
