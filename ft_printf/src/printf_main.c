/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <hmarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 12:04:11 by hmarot            #+#    #+#             */
/*   Updated: 2018/01/26 02:51:30 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *format, ...)
{
	char		*form;
	t_penv		env;
	int			i;
	va_list		ap;

	va_start(ap, format);
	form = (char *)format;
	prf_init(&env);
	env.fd = FD_STDOUT;
	i = 0;
	while (form[i])
	{
		prf_loop(&env);
		i = prf_main_b(form, &env, i, ap);
		if (i == -1)
			return (-1);
	}
	ft_void(write(1, env.buffer, env.pos));
	va_end(ap);
	return (env.ret + env.pos);
}

int		ft_vdprintf(int fd, const char *format, va_list va)
{
	char		*form;
	t_penv		env;
	int			i;

	form = (char *)format;
	prf_init(&env);
	env.fd = fd;
	i = 0;
	while (form[i])
	{
		prf_loop(&env);
		i = prf_main_b(form, &env, i, va);
		if (i == -1)
			return (-1);
	}
	ft_void(write(fd, env.buffer, env.pos));
	return (env.ret + env.pos);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	char		*form;
	t_penv		env;
	int			i;
	va_list		ap;

	va_start(ap, format);
	form = (char *)format;
	prf_init(&env);
	env.fd = fd;
	i = 0;
	while (form[i])
	{
		prf_loop(&env);
		i = prf_main_b(form, &env, i, ap);
		if (i == -1)
			return (-1);
	}
	ft_void(write(fd, env.buffer, env.pos));
	va_end(ap);
	return (env.ret + env.pos);
}

int		prf_main_b(char *form, t_penv *env, int i, va_list ap)
{
	if (form[i] != '%')
		push_buff(form[i], env);
	else
	{
		i = prf_flag(form, i + 1, env);
		if (i == -1)
			return (-1);
		i = prf_field(form, i, env);
		if (i == -1)
			return (-1);
		i = prf_pressi(form, i, env);
		if (i == -1)
			return (-1);
		i = prf_modif(form, i, env);
		if (i == -1)
			return (-1);
		i = prf_conv(form, i, env, ap);
		if (i == -1)
			return (-1);
	}
	++i;
	if (env->err)
		return (-1);
	return (i);
}
