#ifndef __SYSTEM_H
#define __SYSTEM_H

#include <stddef.h> // size_t
#include <stdint.h> // uint?_t

// type definitions

// stack frame before calling `fault_handler`
struct regs {
  uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax; // pushed registers by `pusha`
  uint32_t int_no, err_code;
} __attribute__((packed));

// string.c
size_t strlen(const char* str);

// terminal.c
void terminal_initialize();
void puts(const char* data);
void putchar(char c);

// gdt.c
void gdt_install();

// idt.c
void idt_install();
void idt_set_gate(uint8_t num, uint32_t base, uint16_t selector, uint8_t flags);

// isrs.c
void isrs_install();

// boot.s
void gdt_flush();
void idt_load();
void isr0();

#endif
