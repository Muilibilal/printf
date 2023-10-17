#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int _printf(const char *format, ...);
static void write_character(char c, int *count)
static void write_string(const char *str, int *count)
static void fmt_spec_handler(const char **fmt, va_list *arg_lst, int *p_chrs)
#endif
