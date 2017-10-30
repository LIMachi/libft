/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_get_all.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 10:51:56 by hmartzol          #+#    #+#             */
/*   Updated: 2017/10/30 16:34:59 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** return a list of matched labels in the hashtable, this list is iterable and
** NULL terminated
** a return of NULL can either signal an error or the absence of searched label
*/

/*
** sf_park(LIST, "a")
** abcaba -> bcbaaa
** return visualised as indexes: {0, 2, 3, 5}
** so return[0] is the relinked list to be stored
** and return[2] is the "list" returned by ft_hashtable_get_all
*/

static t_llist	**sf_park(t_llist *node, char *label)
{
	static t_llist		*nodes[4];

	ft_bzero(nodes, sizeof(t_llist*) * 4);
	while (node != NULL)
	{
		if (ft_strcmp(node->label, label))
		{
			nodes[0] = nodes[0] == NULL ? node : nodes[0];
			(void)(nodes[1] != NULL ? nodes[1]->next = node : 0);
			nodes[1] = node;
		}
		else
		{
			nodes[2] = nodes[2] == NULL ? node : nodes[2];
			(void)(nodes[3] != NULL ? nodes[3]->next = node : 0);
			nodes[3] = node;
		}
		node = node->next;
	}
	if (nodes[0] == NULL)
		nodes[0] = nodes[2];
	else
		nodes[1]->next = nodes[2];
	return (nodes);
}

t_list			*ft_hashtable_get_all(t_hashtable *table, char *label)
{
	t_llist	**nodes;
	size_t	index;

	if (table == NULL || label == NULL || table->data == NULL)
		return (NULL);
	if (table->hasher != NULL)
		index = table->hasher(label, table->size);
	else
		index = ft_default_hasher(label, table->size);
	if (index >= table->size)
		return (NULL);
	if ((table->data[index]) == NULL)
		return (NULL);
	if ((nodes = sf_park(table->data[index], label)) == NULL)
		return (NULL);
	table->data[index] = nodes[0];
	return ((t_list*)nodes[2]);
}
