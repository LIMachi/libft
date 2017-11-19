/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 12:49:45 by hmartzol          #+#    #+#             */
/*   Updated: 2017/11/19 13:34:06 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_getopt.h>
#include <libft.h>

t_getopt_env			ft_getopt_env(const char *opstring,
									const t_getopt_opt *longopts)
{
	t_getopt_env	env;

	env = (t_getopt_env){.optind = 1, .opterr = 1, .optopt = 0, .optarg = NULL,
		.longind = NULL, .nextchar = NULL, .ord = PERMUTE,
		.fnop = 1, .lnop = 1, .optstring = 0,
		.longopts = (t_getopt_opt*)longopts};
	if (opstring[0] == '-')
	{
		env.ord = RETURN_IN_ORDER;
		++opstring;
	}
	else if (opstring[0] == '+')
	{
		env.ord = REQUIRE_ORDER;
		++opstring;
	}
	if (opstring[0] == ':')
		env.opterr = 0;
	env.optstring = (char*)opstring;
	return (env);
}
