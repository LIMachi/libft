/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 09:51:07 by hmartzol          #+#    #+#             */
/*   Updated: 2018/01/26 02:17:41 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** get the first occurence of label in the table, the returned node is not
** iterable, use ft_hashtable_get_all to get all occurences (heavier in
** calculation has it sort the table).
** a return of NULL can either signal an error or the absence of searched label
*/

t_llist	*ft_hashtable_get(t_hashtable *table, char *label)
{
	size_t	index;
	t_llist	*node;

	if (table == NULL || label == NULL || table->data == NULL)
		return (NULL);
	if (table->hasher != NULL)
		index = table->hasher(label, table->size);
	else
		index = ft_default_hasher(label, table->size);
	if (index >= table->size)
		return (NULL);
	node = table->data[index];
	while (node != NULL && ft_strcmp(node->label, label))
		node = node->next;
	return (node);
}
