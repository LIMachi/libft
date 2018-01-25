/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_remove.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 09:47:36 by hmartzol          #+#    #+#             */
/*   Updated: 2018/01/24 00:21:33 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** remove all occurences of label in table, return the number of nodes droped
** like ft_hashtable_destroy, del is a facultative pointer to a function to free
** the contents of data in nodes but not data itself
*/

int	ft_hashtable_remove(t_hashtable *table, char *label,
						void (*del)(char *, void *, size_t))
{
	int		dropped;
	t_llist	*node;
	t_llist	*tmp;

	dropped = 0;
	if ((node = (t_llist*)ft_hashtable_get_all(table, label)) == NULL)
		return (0);
	while (node)
	{
		if (del)
			del(node->label, node->data, node->data_size);
		tmp = node->next;
		ft_free(node->label);
		ft_free(node->data);
		ft_free(node);
		++dropped;
		node = tmp;
	}
	return (0);
}
