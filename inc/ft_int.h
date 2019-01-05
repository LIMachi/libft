/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 20:28:37 by hmartzol          #+#    #+#             */
/*   Updated: 2017/11/03 18:22:53 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INT_H
# define FT_INT_H

# define FT_INT_USE_LOGICAL 1

# ifndef __SIZEOF_CHAR__
#  if FT_INT_USE_LOGICAL
#   define __SIZEOF_CHAR__ 1
#  else
#   define __SIZEOF_CHAR__ (sizeof(char))
#  endif
# endif

# ifndef __CHAR_BIT__
#  if FT_INT_USE_LOGICAL
#   define __CHAR_BIT__ 0xFF
#  else
#   define __CHAR_BIT__ ((1 << (__SIZEOF_CHAR__ << 3)) - 1)
#  endif
# endif

# ifndef __SIZEOF_INTMAX_T__
#  if FT_INT_USE_LOGICAL
#   define __SIZEOF_INTMAX_T__ __SIZEOF_LONG_LONG__
#  else
#   define __SIZEOF_INTMAX_T__ (sizeof(__INTMAX_TYPE__))
#  endif
# endif

# define __T_INTMIN	(-1ull >> ((sizeof(unsigned long long) - sizeof(int)) << 3))
# define INTMIN		((int)__T_INTMIN)
# define INTMAX		((int)__T_INTMIN >> 1)

# define TSHORT_BIT	((__SHRT_MAX__ << 1) | 1)
# define TINT_BIT	((__INT_MAX__ << 1) | 1)
# define TLONG_BIT	((__LONG_MAX__ << 1) | 1)
# define TLLONG_BIT	((__LONG_LONG_MAX__ << 1) | 1)
# define TINTMAX_BIT ((__INTMAX_MAX__ << 1) | 1)
# define TSIZE_BIT __SIZE_MAX__
# define TPTRDIFF_BIT ((__PTRDIFF_MAX__ << 1) | 1)

# ifdef __SIZEOF_INT128__

typedef union	u_i128
{
	__UINT64_TYPE__	u64[2];
	__int128_t		i128;
	__uint128_t		u128;
}				t_i128;

# endif

#endif
