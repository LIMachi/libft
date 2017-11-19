/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt_base_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 12:38:15 by hmartzol          #+#    #+#             */
/*   Updated: 2017/11/19 13:42:05 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_getopt.h>
#include <libft.h>

static void		sf_swap(char **a, char **b)
{
	char	*t;

	t = *a;
	*a = *b;
	*b = t;
}

static void		sf_swaper(char **argv, t_getopt_env *env)
{
	int		bottom;
	int		middle;
	int		top;
	int		i;

	bottom = env->fnop;
	middle = env->lnop;
	top = env->optind;
	while (top > middle && middle > bottom && (i = -1))
		if (top - middle > middle - bottom)
		{
			while (++i < middle - bottom)
				sf_swap(&argv[bottom + i], &argv[top - (middle - bottom) + i]);
			top -= middle - bottom;
		}
		else
		{
			while (++i < top - middle)
				sf_swap(&argv[bottom + i], &argv[middle + i]);
			bottom += top - middle;
		}
	env->fnop += (env->optind - env->lnop);
	env->lnop = env->optind;
}

static int		sf_getopt_base_init(int argc, char **argv, t_getopt_env *en)
{
	if (en->optind == argc)
		return (_(en->fnop != en->lnop ? en->optind = en->fnop : 0, -1));
	if (argv[en->optind][0] != '-' || argv[en->optind][1] == '\0')
	{
		if (en->ord == REQUIRE_ORDER)
			return (-1);
		return (_(en->optarg = argv[en->optind++], 1));
	}
	if (en->longopts != NULL && argv[en->optind][1] == '-')
	{
		en->nextchar = argv[en->optind] + 2;
		return (ft_getopt_base_longopt(argc, argv, en, "--"));
	}
	en->nextchar = argv[en->optind] + 1;
	return (0);
}

int				ft_getopt_base_init(int argc, char **argv, t_getopt_env *env)
{
	env->lnop = env->lnop > env->optind ? env->optind : env->lnop;
	env->fnop = env->fnop > env->optind ? env->optind : env->fnop;
	if (env->ord == PERMUTE)
	{
		if (env->fnop != env->lnop && env->lnop != env->optind)
			sf_swaper(argv, env);
		else if (env->lnop != env->optind)
			env->fnop = env->optind;
		while (env->optind < argc && (argv[env->optind][0] != '-' ||
				argv[env->optind][1] == '\0'))
			env->optind++;
		env->lnop = env->optind;
	}
	if (env->optind != argc && !ft_strcmp(argv[env->optind], "--"))
	{
		env->optind++;
		if (env->fnop != env->lnop && env->lnop != env->optind)
			sf_swaper(argv, env);
		else if (env->fnop == env->lnop)
			env->fnop = env->optind;
		env->lnop = argc;
		env->optind = argc;
	}
	return (sf_getopt_base_init(argc, argv, env));
}
