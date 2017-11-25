/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 08:03:58 by hmartzol          #+#    #+#             */
/*   Updated: 2017/11/25 16:40:40 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_getopt.h>
#include <libft.h>

/*
** return values:
** '?' invalid/malformed option
** -1 parsing ended
** 0 (imposible to get, should be considered as an error)
** 1 non option (not an error nor end of parsing, might occur on PERMUTE and
**  RETURN_IN_ORDER)
** -2 reserved
** >1 || <-2: user defined return
*/

static int				sf_getopt_base_long(int argc, char **argv,
											t_getopt_env *env, char c)
{
	if (*env->nextchar != '\0')
		env->optarg = env->nextchar;
	else if (env->optind == argc)
	{
		if (env->opterr)
			ft_dprintf(FD_STDERR,
				"%s: option requires an argument -- '%c'\n", argv[0], c);
		env->optopt = c;
		return (env->optstring[0] == ':' ? ':' : '?');
	}
	else
		env->optarg = argv[env->optind];
	env->nextchar = env->optarg;
	env->optarg = NULL;
	return (ft_getopt_base_longopt(argc, argv, env, "-W"));
}

static int				sf_getopt_base_opt(int argc, char **argv,
											t_getopt_env *env, int c)
{
	if (*env->nextchar != '\0')
		_(env->optarg = env->nextchar, ++env->optind);
	else if (env->optind == argc)
	{
		if (env->opterr)
			ft_dprintf(FD_STDERR,
					"%s: option requires an argument -- '%c'\n", argv[0], c);
		env->optopt = c;
		c = env->optstring[0] == ':' ? ':' : '?';
	}
	else
		env->optarg = argv[env->optind++];
	env->nextchar = NULL;
	return (c);
}

static int				sf_fak_la_norme(char **argv, t_getopt_env *env, char c)
{
	if (env->opterr)
		ft_dprintf(FD_STDERR, "%s: invalid option -- '%c'\n", argv[0], c);
	env->optopt = c;
	return ('?');
}

int						ft_getopt(int argc, char **argv, t_getopt_env *env)
{
	int		r;
	char	c;
	char	*t;

	if (argc < 1)
		return (-1);
	env->optarg = NULL;
	if (env->nextchar == NULL || *env->nextchar == '\0')
		if ((r = ft_getopt_base_init(argc, argv, env)))
			return (r);
	c = *env->nextchar++;
	t = ft_strchr(env->optstring, c);
	(void)(*env->nextchar == '\0' ? ++env->optind : 0);
	if (t == NULL || c == ':' || c == ';')
		return (sf_fak_la_norme(argv, env, c));
	if (t[0] == 'W' && t[1] == ';' && env->longopts != NULL)
		return (sf_getopt_base_long(argc, argv, env, c));
	if (t[1] == ':' && t[2] == ':')
		_(*env->nextchar != '\0' ? env->optarg = _(++env->optind,
			env->nextchar) : NULL, env->nextchar = NULL);
	else if (t[1] == ':')
		return (sf_getopt_base_opt(argc, argv, env, c));
	return (c);
}
