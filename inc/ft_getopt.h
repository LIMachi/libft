/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 12:39:41 by hmartzol          #+#    #+#             */
/*   Updated: 2017/11/25 16:40:34 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H

typedef enum		e_getopt_ord
{
	REQUIRE_ORDER, PERMUTE, RETURN_IN_ORDER
}					t_getopt_ord;

typedef struct		s_getopt_opt
{
	int				val;
	char			*name;
	int				has_arg;
	int				*flag;
}					t_getopt_opt;

typedef struct		s_getopt_env
{
	int				optind;
	int				opterr;
	int				optopt;
	char			*optarg;
	int				*longind;
	char			*nextchar;
	t_getopt_ord	ord;
	int				fnop;
	int				lnop;
	char			*optstring;
	t_getopt_opt	*longopts;
}					t_getopt_env;

t_getopt_env		ft_getopt_env(const char *opstring,
								const t_getopt_opt *longopts);
int					ft_getopt_base_init(int argc, char **argv,
										t_getopt_env *env);
int					ft_getopt_base_longopt(int argc, char **argv,
										t_getopt_env *env, char *prefix);

int					ft_getopt(int argc, char **argv, t_getopt_env *env);

#endif
