/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_destroy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 10:42:35 by hmartzol          #+#    #+#             */
/*   Updated: 2017/10/30 16:29:08 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** free the content of table, but not table itself
*/

void	ft_hashtable_destroy(t_hashtable *table,
							void (*del)(char *, void *, size_t))
{
	size_t	i;
	t_llist	*node;
	t_llist	*tmp;

	if (table == NULL || table->data == NULL)
		return ;
	i = -1;
	while (++i < table->size)
	{
		node = table->data[i];
		while (node != NULL)
		{
			del(node->label, node->data, node->data_size);
			tmp = node->next;
			ft_free(node);
			node = tmp;
		}
	}
	ft_memdel((void**)&table->data);
	table->size = 0;
	table->hasher = NULL;
}
