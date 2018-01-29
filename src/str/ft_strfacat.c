/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfacat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 04:25:01 by hmartzol          #+#    #+#             */
/*   Updated: 2018/01/29 04:26:52 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strfacat(char *str1, char *str2)
{
	size_t	size;
	char	*out;
	char	*ptr;

	if (str1 == NULL && str2 == NULL)
		return (NULL);
	if (str1 == NULL)
		return (_(out = ft_strndup(str2, ft_strlen(str2)), ft_free(str2), out));
	if (str2 == NULL)
		return (_(out = ft_strndup(str1, ft_strlen(str1)), ft_free(str1), out));
	size = ft_strlen(str1) + ft_strlen(str2) + 1;
	if ((out = (char*)ft_malloc(size * sizeof(char))) == NULL)
		return (NULL);
	ptr = out;
	while (*str1)
		*ptr++ = *str1++;
	while (*str2)
		*ptr++ = *str2++;
	*ptr = '\0';
	ft_free(str1);
	ft_free(str2);
	return (out);
}
