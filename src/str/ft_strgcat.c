/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 04:29:08 by hmartzol          #+#    #+#             */
/*   Updated: 2018/01/29 04:51:34 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

inline static char	*local_cat(char *s1, char *s2, int m)
{
	char	*p;

	if ((p = s2) != NULL)
	{
		while (*s2)
			*s1++ = *s2++;
		if (m)
			ft_free(p);
	}
	return (s1);
}

char				*ft_strgcat(int n, ...)
{
	va_list	va;
	size_t	len;
	int		i;
	char	*out;
	char	*p;

	va_start(va, n);
	i = -1;
	len = 0;
	while (++i < n)
	{
		if ((p = va_arg(va, char *)) != NULL)
			len += ft_strlen(p);
		(void)va_arg(va, int);
	}
	va_end(va);
	if ((out = ft_malloc(++len)) == NULL)
		return (NULL);
	va_start(va, n);
	i = -1;
	p = out;
	while (++i < n)
		p = local_cat(p, va_arg(va, char *), va_arg(va, int));
	out[len - 1] = '\0';
	return (out);
}
