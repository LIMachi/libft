AUTHOR = hmartzol
NAME = libft.a
SRCDIR = .
INCDIRS = inc ft_printf/inc
OBJDIR = .obj
MAIN = main.c
CFLAGS = -Wall -Wextra -Werror -g -DDISABLE_FT_ERROR
include ../Makefiles/Makefile.gen
