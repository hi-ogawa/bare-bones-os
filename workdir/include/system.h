#ifndef __SYSTEM_H
#define __SYSTEM_H

#include <stddef.h> // size_t
#include <stdint.h> // uint?_t

// string.c
size_t strlen(const char* str);

// terminal.c
void terminal_initialize();
void puts(const char* data);
void putchar(char c);

#endif
