#include <system.h> // terminal_initialize, puts, putchar, gdt_install, idt_install
                    // isrs_install

void kernel_main() {
  gdt_install();
  idt_install();
  isrs_install();
  asm volatile ("sti"); // enable interrupt after ISR is setup
  terminal_initialize();
  puts("Hello, kernel World!\nHello, again!\n");
  int x = 5;
  int y = 0;
  // trigger "divide by zero" exception
  putchar(x / y);
}
