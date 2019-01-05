include ../Makefiles/default_var.mk

NAME := libft.a
TEST_SRCS := main.c
CFLAGS += -Ift_printf/inc

ifeq ($(shell $(CC) -dM -E - < /dev/null | grep __int128_t), )
$(info missing __int128_t)
BLACK_LIST_SRCS += _i128 _u128 _b128 _x128 _o128
endif

include ../Makefiles/lib.mk