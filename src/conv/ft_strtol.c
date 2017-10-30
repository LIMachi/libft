/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 23:15:33 by hmartzol          #+#    #+#             */
/*   Updated: 2017/10/30 16:22:37 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <limits.h>
#include <stdio.h>

inline static int	sf_get_base(char **end, int base)
{
	if (base == 0)
	{
		if (**end == '0')
		{
			if (*(++*end) == 'x' || **end == 'X')
				return (_(++*end, 16));
			if (*(++*end) == 'b' || **end == 'B')
				return (_(++*end, 2));
			return (8);
		}
		return (10);
	}
	if (base == 16 && **end == '0' &&
			(*(*end + 1) == 'x' || *(*end + 1) == 'X'))
		return (_(*end += 2, 16));
	if (base == 2 && **end == '0' &&
			(*(*end + 1) == 'b' || *(*end + 1) == 'B'))
		return (_(*end += 2, 2));
	return (base);
}

/*
** thanks to 42's norm, this is one of the worst unreadable function i have ever
** writen
*/

long long			ft_strtoll(const char *nptr, char **end, int base)
{
	int					s;
	unsigned long long	t[3];

	(void)(end == NULL ? end = (char**)(void*[1]){NULL} : 0);
	*end = (char*)nptr;
	if (!(base == 0 || (base >= 2 && base <= 36)))
		return (0 & ft_error(EINVAL, "invalid base size"));
	while (ft_isspace(**end))
		++*end;
	s = **end == '-' || **end == '+' ? _(++*end, 44 - *(*end - 1)) : 1;
	base = sf_get_base(end, base);
	(void)_(t[0] = 0, --*end);
	while (_(t[1] = t[0], ft_isalnum(*++*end)))
	{
		if ((t[2] = **end - '0' * ft_isdigit(**end) -
				'a' * ft_islower(**end) - 'A' * ft_isupper(**end) +
				10 * ft_isalpha(**end)) >= (unsigned long long)base)
			break ;
		if ((t[0] = t[0] * base + t[2]) < t[1])
			return ((s ? LLONG_MIN : LLONG_MAX) | (0 & ft_error(ERANGE, "")));
	}
	if ((t[0] & (1ull << ((__SIZEOF_LONG_LONG__ << 3) - 1))) &&
		(t[0] & (((unsigned long long)-1) >> 1)))
		return ((s ? LLONG_MIN : LLONG_MAX) | (0 & ft_error(ERANGE, "")));
	return (s * (long long)t[0]);
}
