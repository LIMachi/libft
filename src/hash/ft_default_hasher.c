/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_default_hasher.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 09:54:52 by hmartzol          #+#    #+#             */
/*   Updated: 2017/10/23 11:44:55 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** default hash function to be used by an hashtable if no hasher was found
*/

size_t	ft_default_hasher(char *label, size_t max)
{
	int		i;
	size_t	out;

	out = 0;
	i = 0;
	while (label[i])
		out += label[i++];
	return (out % max);
}
