include ../Makefiles/default_var.mk

NAME := libft.a
CFLAGS += -Ift_printf/inc

ifeq ($(shell $(CC) -dM -E - < /dev/null | grep __SIZEOF_INT128__), )
$(info missing __int128_t)
BLACK_LIST_SRCS += _i128 _u128 _b128 _x128 _o128
endif

include ../Makefiles/lib.mk
