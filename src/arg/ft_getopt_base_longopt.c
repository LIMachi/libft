/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt_base_longopt.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 12:41:18 by hmartzol          #+#    #+#             */
/*   Updated: 2017/11/19 15:15:23 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_getopt.h>
#include <libft.h>

int		sf_getopt_base_longopt_1(int argc, char **argv, t_getopt_env *env,
								char **ptr)
{
	if (env->optind < argc)
		env->optarg = argv[env->optind++];
	else
	{
		if (env->opterr)
			ft_dprintf(FD_STDERR,
				"%s: option '%s%s' requires an argument\n",
				argv[0], ptr[0], env->longopts[(int)ptr[2]].name);
		env->optopt = env->longopts[(int)ptr[2]].val;
		return (env->optstring[0] == ':' ? ':' : '?');
	}
	if (env->longind != NULL)
		*env->longind = (int)ptr[2];
	if (env->longopts[(int)ptr[2]].flag != NULL)
	{
		*env->longopts[(int)ptr[2]].flag = env->longopts[(int)ptr[2]].val;
		return (0);
	}
	return (env->longopts[(int)ptr[2]].val);
}

int		sf_getopt_base_longopt_0(int argc, char **argv, t_getopt_env *env,
								char **ptr)
{
	++env->optind;
	env->nextchar = NULL;
	if (*ptr[1])
	{
		if (env->longopts[(int)ptr[2]].has_arg)
			env->optarg = ptr[1] + 1;
		else
		{
			if (env->opterr)
				ft_dprintf(FD_STDERR,
					"%s: option '%s%s' doesn't allow an argument\n",
					argv[0], ptr[0], env->longopts[(int)ptr[2]].name);
			env->optopt = env->longopts[(int)ptr[2]].val;
			return ('?');
		}
	}
	else if (env->longopts[(int)ptr[2]].has_arg == 1)
		sf_getopt_base_longopt_1(argc, argv, env, ptr);
	return (env->longopts[(int)ptr[2]].val);
}

int		ft_getopt_base_longopt(int argc, char **argv, t_getopt_env *env,
								char *prefix)
{
	char			*end;
	int				op;

	end = env->nextchar;
	while (*end && *end != '=')
		++end;
	op = -1;
	while (env->longopts[++op].name != NULL)
		if (!ft_strncmp(env->longopts[op].name, env->nextchar,
				end - env->nextchar))
			break ;
	if (env->longopts[op].name == NULL)
	{
		if (argv[env->optind][1] == '-' ||
			ft_strchr(env->optstring, *env->nextchar) == NULL)
		{
			(void)(env->opterr ? ft_dprintf(FD_STDERR,
	"%s: unrecognized option '%s%s'\n", argv[0], prefix, env->nextchar) : 0);
			_(env->nextchar = NULL, ++env->optind);
			return (_(env->optopt = 0, '?'));
		}
		return (-1);
	}
	return (sf_getopt_base_longopt_0(argc, argv, env,
			(char*[3]){prefix, end, (char*)(size_t)op}));
}
