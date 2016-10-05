/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:52:52 by hmartzol          #+#    #+#             */
/*   Updated: 2016/02/08 18:46:48 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_ishexa(char c)
{
	return (ft_isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}

static int		ft_atoi0(char *p_tmp)
{
	int	out;

	out = 0;
	if (*p_tmp == 'x' || *p_tmp == 'X')
		while (ft_ishexa(*++p_tmp))
			out = 16 * out + ft_isdigit(*p_tmp) * (*p_tmp - '0') +
				(*p_tmp >= 'A' && *p_tmp <= 'F') * (*p_tmp - 'A' + 10) +
				(*p_tmp >= 'a' && *p_tmp <= 'f') * (*p_tmp - 'a' + 10);
	else
	{
		if (*p_tmp == 'b' || *p_tmp == 'B')
		{
			++p_tmp;
			while (*p_tmp == '0' || *p_tmp == '1')
				out = 2 * out + *p_tmp++ - '0';
		}
		else
			while (*p_tmp >= '0' && *p_tmp <= '7')
				out = 8 * out + *p_tmp++ - '0';
	}
	return (out);
}

int				ft_atoi(const char *str)
{
	int		out;
	int		sign;
	char	*p_tmp;

	p_tmp = (char*)str;
	sign = 1;
	out = 0;
	while (ft_isspace(*p_tmp))
		++p_tmp;
	if (*p_tmp == '+' || *p_tmp == '-')
		if (*p_tmp++ == '-')
			sign = -1;
	if (*p_tmp == '0')
		out = ft_atoi0(p_tmp + 1);
	else
		while (ft_isdigit(*p_tmp))
			out = 10 * out + *p_tmp++ - '0';
	return (sign * out);
}
