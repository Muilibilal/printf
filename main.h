#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

void write_character(char c, int *count);
void write_string(const char *str, int *count);
void integer_to_string_converter(int num, char *str);
void fmt_spec_handler(const char **fmt, va_list *arg_lst, int *p_chrs);
int _printf(const char *format, ...);

#endif
