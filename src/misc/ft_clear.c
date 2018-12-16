/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 19:34:13 by hmartzol          #+#    #+#             */
/*   Updated: 2016/12/18 23:30:16 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_clear(char *form, ...)
{
	va_list	va;
	void	*out;

	out = NULL;
	if (form == NULL)
		return (out);
	va_start(va, form);
	while (*form != '\0')
	{
		if (*form == 'd')
			close(va_arg(va, int));
		else if (*form == 'p')
			free(va_arg(va, void *));
		else if (*form == 'r')
			out = va_arg(va, void *);
		++form;
	}
	va_end(va);
	return (out);
}
